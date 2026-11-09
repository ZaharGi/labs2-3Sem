package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
	"strings"
)

type LRUCache struct {
	capacity int
	items    *list.List
	cache    map[int]*list.Element
}

type lruItem struct {
	key, value int
}

func NewLRUCache(cap int) *LRUCache {
	return &LRUCache{
		capacity: cap,
		items:    list.New(),
		cache:    make(map[int]*list.Element),
	}
}

func (c *LRUCache) Get(key int) int {
	if el, ok := c.cache[key]; ok {
		c.items.MoveToFront(el)
		return el.Value.(*lruItem).value
	}
	return -1
}

func (c *LRUCache) Put(key, value int) {
	if el, ok := c.cache[key]; ok {
		c.items.MoveToFront(el)
		el.Value.(*lruItem).value = value
		return
	}
	if c.items.Len() == c.capacity {
		back := c.items.Back()
		if back != nil {
			item := back.Value.(*lruItem)
			delete(c.cache, item.key)
			c.items.Remove(back)
		}
	}
	el := c.items.PushFront(&lruItem{key, value})
	c.cache[key] = el
}

func runLRUTask() {
	var cap, q int
	fmt.Print("Емкость кэша: ")
	fmt.Scan(&cap)
	fmt.Print("Количество запросов: ")
	fmt.Scan(&q)
	// Очистка буфера после fmt.Scan
	reader := bufio.NewReader(os.Stdin)
	reader.ReadString('\n')

	fmt.Println("Введите запросы (SET x y, GET x):")
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(line)

	cache := NewLRUCache(cap)
	for i := 0; i < len(parts); i++ {
		if parts[i] == "SET" {
			var k, v int
			fmt.Sscanf(parts[i+1], "%d", &k)
			fmt.Sscanf(parts[i+2], "%d", &v)
			cache.Put(k, v)
			i += 2
		} else if parts[i] == "GET" {
			var k int
			fmt.Sscanf(parts[i+1], "%d", &k)
			fmt.Print(cache.Get(k), " ")
			i += 1
		}
	}
	fmt.Println()
}
