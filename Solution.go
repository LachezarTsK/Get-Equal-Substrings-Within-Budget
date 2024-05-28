
package main

import (
	"fmt"
	"math"
)

func equalSubstring(firstInput string, secondInput string, maxCost int) int {
	maxLengthForMaxCost := 0
	front := 0
	back := 0
	cost := 0

	for front < len(firstInput) {
		cost = cost + int(math.Abs(float64(firstInput[front])-float64(secondInput[front])))

		for cost > maxCost && back < len(firstInput) {
			cost = cost - int(math.Abs(float64(firstInput[back])-float64(secondInput[back])))
			back++
		}
		maxLengthForMaxCost = max(maxLengthForMaxCost, front-back+1)
		front++
	}

	return maxLengthForMaxCost
}
