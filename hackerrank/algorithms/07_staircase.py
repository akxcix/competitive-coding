#!/bin/python3

import sys

def staircase(n):
    # Complete this function
    i = n
    while i >0:
        print(' '*(i-1)+'#'*(n-i+1))
        i-=1

if __name__ == "__main__":
    n = int(input().strip())
    staircase(n)

