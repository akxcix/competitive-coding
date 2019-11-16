// package main

// import (
// 	"bufio"
// 	"os"
// 	"strconv"
// )

// func main() {
// 	scanner := bufio.NewScanner(os.Stdin)
// 	scanner.Scan()
// 	input := scanner.Text()
// 	nq, _ := strconv.Atoi(input)
// 	for queryNo := 0; queryNo < nq; queryNo++ {
// 		scanner.Scan()
// 		input := scanner.Text()
// 		q := input[0]
// 		val, _ := strconv.Atoi(input[2:])

// 	}
// }

// // AVLNode is a AVL tree node
// type AVLNode struct {
// 	val    int
// 	lchild *AVLNode
// 	rchild *AVLNode
// 	h      int
// }
