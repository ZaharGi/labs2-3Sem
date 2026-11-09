package main
import "fmt"

type MyArray struct {
	data  []string
	count int
}

func NewArray() *MyArray {
	return &MyArray{data: make([]string, 0)}
}

func (a *MyArray) PushBack(v string) {
	a.data = append(a.data, v)
	a.count++
}

func (a *MyArray) Print() {
	if a.count == 0 {
		fmt.Println("(empty)")
		return
	}
	for i, v := range a.data {
		fmt.Printf("%d:%s\n", i, v)
	}
}
