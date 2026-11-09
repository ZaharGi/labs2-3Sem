package main

import (
	"fmt"
	"os"
)

type MenuOption int

const (
	Exit MenuOption = iota
	StackInfixToPostfix
	SetCLI
	SetOperations
	ArrayPatternMatch
	TreeAVLCheck
	RomanConversion
	LRUCache
)

func printMenu() {
	fmt.Println("1. Стек")
	fmt.Println("2. Множество")
	fmt.Println("3. Множество (Объединение, Пересечение, Разность)")
	fmt.Println("4. Массив")
	fmt.Println("5. Дерево")
	fmt.Println("6. Хеш-таблица")
	fmt.Println("7. LRU-кэш")
	fmt.Println("0. Выход")
	fmt.Print("Выберите задание: ")
}

func main() {
	filename := "data.txt"
	query := ""

	for i := 1; i < len(os.Args); i++ {
		if os.Args[i] == "--file" && i+1 < len(os.Args) {
			filename = os.Args[i+1]
			i++
		} else if os.Args[i] == "--query" && i+1 < len(os.Args) {
			query = os.Args[i+1]
			i++
		}
	}

	if query != "" {
		executeQuery(filename, query)
		return
	}

	for {
		printMenu()
		var choice int
		_, err := fmt.Scan(&choice)
		if err != nil {
			var dummy string
			fmt.Scanln(&dummy)
			continue
		}

		switch MenuOption(choice) {
		case Exit:
			fmt.Println("Выход...")
			return
		case StackInfixToPostfix:
			runStackTask()
		case SetCLI:
			var cmd, val string
			fmt.Print("Введите запрос (SETADD/SETDEL/SET_AT + слово): ")
			fmt.Scan(&cmd, &val)
			executeQuery("data.txt", cmd+" "+val)
		case SetOperations:
			runSetOperations()
		case ArrayPatternMatch:
			runPatternMatch()
		case TreeAVLCheck:
			runTreeTask()
		case RomanConversion:
			runRomanTask()
		case LRUCache:
			runLRUTask()
		default:
			fmt.Println("Неверный пункт меню")
		}
	}
}
