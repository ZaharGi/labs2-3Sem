package main

import (
	"fmt"
	"math"
)

type TreeNode struct {
	value int
	left  *TreeNode
	right *TreeNode
}

func insertNode(root *TreeNode, v int) *TreeNode {
	if root == nil {
		return &TreeNode{value: v}
	}
	if v < root.value {
		root.left = insertNode(root.left, v)
	} else if v > root.value {
		root.right = insertNode(root.right, v)
	}
	return root
}

func checkAVLHelper(root *TreeNode, balanced *bool) int {
	if root == nil {
		return 0
	}
	leftH := checkAVLHelper(root.left, balanced)
	rightH := checkAVLHelper(root.right, balanced)
	if math.Abs(float64(leftH-rightH)) > 1 {
		*balanced = false
	}
	return int(math.Max(float64(leftH), float64(rightH))) + 1
}

func isAVL(root *TreeNode) bool {
	balanced := true
	checkAVLHelper(root, &balanced)
	return balanced
}

func runTreeTask() {
	var n, val int
	fmt.Print("Сколько чисел? ")
	fmt.Scan(&n)
	fmt.Println("Введите числа:")
	var root *TreeNode
	for i := 0; i < n; i++ {
		fmt.Scan(&val)
		root = insertNode(root, val)
	}
	if isAVL(root) {
		fmt.Println("Сбалансировано (AVL): YES")
	} else {
		fmt.Println("Сбалансировано (AVL): NO")
	}
}
