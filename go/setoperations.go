package main

import "fmt"

func runSetOperations() {
	setA := NewHashSet(16)
	setB := NewHashSet(16)
	var val string

	fmt.Print("Элементы 1-го мн-ва (end для конца): ")
	for {
		fmt.Scan(&val)
		if val == "end" {
			break
		}
		setA.Add(val, "")
	}
	fmt.Print("Элементы 2-го мн-ва (end для конца): ")
	for {
		fmt.Scan(&val)
		if val == "end" {
			break
		}
		setB.Add(val, "")
	}

	fmt.Print("Множество A: { ")
	setA.ForEach(func(k, v string) { fmt.Print(k, " ") })
	fmt.Println("}")

	fmt.Print("Множество B: { ")
	setB.ForEach(func(k, v string) { fmt.Print(k, " ") })
	fmt.Println("}")

	// Объединение
	uni := NewHashSet(16)
	setA.ForEach(func(k, v string) { uni.Add(k, "") })
	setB.ForEach(func(k, v string) { uni.Add(k, "") })
	fmt.Print("Объединение: { ")
	uni.ForEach(func(k, v string) { fmt.Print(k, " ") })
	fmt.Println("}")

	// Пересечение
	inter := NewHashSet(16)
	setA.ForEach(func(k, v string) {
		if setB.Contains(k) {
			inter.Add(k, "")
		}
	})
	fmt.Print("Пересечение: { ")
	inter.ForEach(func(k, v string) { fmt.Print(k, " ") })
	fmt.Println("}")

	// Разность
	diff := NewHashSet(16)
	setA.ForEach(func(k, v string) {
		if !setB.Contains(k) {
			diff.Add(k, "")
		}
	})
	fmt.Print("Разность: { ")
	diff.ForEach(func(k, v string) { fmt.Print(k, " ") })
	fmt.Println("}")
}
