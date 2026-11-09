package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type HashNode struct {
	key   string
	value string
	next  *HashNode
}

type HashSet struct {
	table    []*HashNode
	capacity int
	count    int
}

func NewHashSet(cap int) *HashSet {
	return &HashSet{table: make([]*HashNode, cap), capacity: cap}
}

func (h *HashSet) hash(s string) uint64 {
	var hash uint64 = 14695981039346656037
	for i := 0; i < len(s); i++ {
		hash ^= uint64(s[i])
		hash *= 1099511628211
	}
	return hash
}

func (h *HashSet) Add(key, value string) {
	if float64(h.count)/float64(h.capacity) > 0.75 {
		h.rehash()
	}
	idx := int(h.hash(key) % uint64(h.capacity))
	curr := h.table[idx]
	for curr != nil {
		if curr.key == key {
			curr.value = value // Обновляем, если есть
			return
		}
		curr = curr.next
	}
	h.table[idx] = &HashNode{key: key, value: value, next: h.table[idx]}
	h.count++
}

func (h *HashSet) rehash() {
	old := h.table
	h.capacity *= 2
	h.table = make([]*HashNode, h.capacity)
	h.count = 0
	for _, head := range old {
		for curr := head; curr != nil; curr = curr.next {
			h.Add(curr.key, curr.value)
		}
	}
}

func (h *HashSet) Get(key string) string {
	idx := int(h.hash(key) % uint64(h.capacity))
	curr := h.table[idx]
	for curr != nil {
		if curr.key == key {
			return curr.value
		}
		curr = curr.next
	}
	return ""
}

func (h *HashSet) Contains(key string) bool {
	return h.Get(key) != ""
}

func (h *HashSet) Del(key string) bool {
	idx := int(h.hash(key) % uint64(h.capacity))
	curr := h.table[idx]
	var prev *HashNode
	for curr != nil {
		if curr.key == key {
			if prev != nil {
				prev.next = curr.next
			} else {
				h.table[idx] = curr.next
			}
			h.count--
			return true
		}
		prev = curr
		curr = curr.next
	}
	return false
}

func (h *HashSet) ForEach(f func(k, v string)) {
	for _, head := range h.table {
		for curr := head; curr != nil; curr = curr.next {
			f(curr.key, curr.value)
		}
	}
}

func (h *HashSet) SaveToFile(filename string) {
	f, _ := os.Create(filename)
	defer f.Close()
	h.ForEach(func(k, v string) {
		f.WriteString(k + "\n")
	})
}

func (h *HashSet) LoadFromFile(filename string) {
	f, err := os.Open(filename)
	if err != nil {
		return
	}
	defer f.Close()
	sc := bufio.NewScanner(f)
	for sc.Scan() {
		line := strings.TrimSpace(sc.Text())
		if line != "" {
			h.Add(line, "")
		}
	}
}

func executeQuery(filename, query string) {
	set := NewHashSet(16)
	set.LoadFromFile(filename)

	parts := strings.Fields(query)
	if len(parts) < 2 {
		return
	}
	cmd, val := parts[0], parts[1]

	if cmd == "SETADD" {
		set.Add(val, "")
		fmt.Println("Added:", val)
	} else if cmd == "SETDEL" {
		if set.Del(val) {
			fmt.Println("Deleted:", val)
		} else {
			fmt.Println("Element not found")
		}
	} else if cmd == "SET_AT" {
		if set.Contains(val) {
			fmt.Println("TRUE")
		} else {
			fmt.Println("FALSE")
		}
	}
	set.SaveToFile(filename)
}
