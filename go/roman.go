package main

import (
	"fmt"
	"strconv"
)

func intToRoman(num int) string {
	set := NewHashSet(16)
	set.Add("1000", "M")
	set.Add("900", "CM")
	set.Add("500", "D")
	set.Add("400", "CD")
	set.Add("100", "C")
	set.Add("90", "XC")
	set.Add("50", "L")
	set.Add("40", "XL")
	set.Add("10", "X")
	set.Add("9", "IX")
	set.Add("5", "V")
	set.Add("4", "IV")
	set.Add("1", "I")

	keys := []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	result := ""

	for _, k := range keys {
		sym := set.Get(strconv.Itoa(k))
		for num >= k {
			result += sym
			num -= k
		}
	}
	return result
}

func runRomanTask() {
	var num int
	fmt.Print("Введите целое число: ")
	fmt.Scan(&num)
	fmt.Println("Римская запись:", intToRoman(num))
}
