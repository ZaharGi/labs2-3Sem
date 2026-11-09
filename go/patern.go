package main

import "fmt"

func isMatch(s, p string) bool {
	m, n := len(s), len(p)
	dp := make([]bool, n+1)
	dp[0] = true

	for j := 1; j <= n; j++ {
		if p[j-1] == '*' {
			dp[j] = dp[j-1]
		}
	}

	for i := 1; i <= m; i++ {
		curr := make([]bool, n+1)
		for j := 1; j <= n; j++ {
			if p[j-1] == '*' {
				curr[j] = curr[j-1] || dp[j]
			} else if p[j-1] == '?' || s[i-1] == p[j-1] {
				curr[j] = dp[j-1]
			}
		}
		dp = curr
	}
	return dp[n]
}

func runPatternMatch() {
	var s, p string
	fmt.Print("Введите строку: ")
	fmt.Scanln(&s)
	fmt.Print("Введите шаблон (с * и ?): ")
	fmt.Scanln(&p)
	if isMatch(s, p) {
		fmt.Println("Соответствует")
	} else {
		fmt.Println("Не соответствует")
	}
}
