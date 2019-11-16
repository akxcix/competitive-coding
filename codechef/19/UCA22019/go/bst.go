package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Node struct {
	data int
	l    *Node
	r    *Node
}

func (n *Node) insert(x int) {
	if n != nil {
		if x > n.data {
			if n.r == nil {
				n.r = &Node{x, nil, nil}
			} else {
				n.r.insert(x)
			}
		} else if x < n.data {
			if n.l == nil {
				n.l = &Node{x, nil, nil}
			} else {
				n.l.insert(x)
			}
		}
	}
}

func (n *Node) inorder() {
	if n != nil {
		n.l.inorder()
		fmt.Print(n.data, " ")
		n.r.inorder()
	}
}

type BST struct {
	root *Node
}

func (b *BST) insert(x int) {
	if b.root == nil {
		b.root = &Node{x, nil, nil}
	} else {
		b.root.insert(x)
	}
}

func (b *BST) inorder() {
	if b.root != nil {
		b.root.inorder()
	}
}

func main() {
	var tree BST
	scanner := bufio.NewScanner(os.Stdin)
	fmt.Println("How many nodes?")
	scanner.Scan()
	nodes, _ := strconv.Atoi(scanner.Text())
	for i := 0; i < nodes; i++ {
		fmt.Println("Input value")
		scanner.Scan()
		x, _ := strconv.Atoi(scanner.Text())
		tree.insert(x)
	}
	tree.inorder()
}
