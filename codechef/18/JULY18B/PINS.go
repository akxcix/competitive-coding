package main

import (
	"bufio"
	"fmt"
	"math"
	"math/big"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())
	for testCase := 0; testCase < t; testCase++ {
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())
		var p int = 1
		q := math.Pow(10, float64(n/2))
		qInt := int(q)
		qBig := big.NewInt(int64(qInt))
		fmt.Println(p, qBig)
	}
}
