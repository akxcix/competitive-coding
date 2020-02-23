#!/bin/python3

import sys

def plusMinus(arr):
    plus=minus=zero=0
    for i in range(len(arr)):
        if arr[i]>0:
            plus+=1
        if arr[i]<0:
            minus+=1
        if arr[i]==0:
            zero+=1
    total = plus+minus+zero
    float(total)
    print(plus/total)
    print(minus/total)
    print(zero/total)

if __name__ == "__main__":
    n = int(input().strip())
    arr = list(map(int, input().strip().split(' ')))
    plusMinus(arr)

