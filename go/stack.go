package main

import (
	"fmt"
	"strings"
	"unicode"
)

type SNode struct {
	value byte
	next  *SNode
}

type Stack struct {
	head *SNode
}

func (s *Stack) Push(v byte) {
	s.head = &SNode{value: v, next: s.head}
}

func (s *Stack) Pop() byte {
	if s.head == nil {
		return 0
	}
	val := s.head.value
	s.head = s.head.next
	return val
}

func (s *Stack) Top() byte {
	if s.head == nil {
		return 0
	}
	return s.head.value
}

func (s *Stack) Empty() bool {
	return s.head == nil
}

func getPriority(op byte) int {
	if op == '+' || op == '-' {
		return 1
	}
	if op == '*' || op == '/' {
		return 2
	}
	return 0
}

func infixToPostfix(expr string) string {
	stack := &Stack{}
	var result strings.Builder

	for i := 0; i < len(expr); i++ {
		c := expr[i]
		if unicode.IsSpace(rune(c)) {
			continue
		}

		if unicode.IsLetter(rune(c)) || unicode.IsDigit(rune(c)) {
			result.WriteByte(c)
		} else if c == '(' {
			stack.Push(c)
		} else if c == ')' {
			for !stack.Empty() && stack.Top() != '(' {
				result.WriteByte(stack.Pop())
			}
			if !stack.Empty() {
				stack.Pop() // Удаляем '('
			}
		} else {
			for !stack.Empty() && getPriority(stack.Top()) >= getPriority(c) {
				result.WriteByte(stack.Pop())
			}
			stack.Push(c)
		}
	}

	for !stack.Empty() {
		result.WriteByte(stack.Pop())
	}
	return result.String()
}

func runStackTask() {
	fmt.Print("Введите инфиксное выражение: ")
	var expr string
	fmt.Scanln(&expr)
	fmt.Println("Постфиксная запись:", infixToPostfix(expr))
}
