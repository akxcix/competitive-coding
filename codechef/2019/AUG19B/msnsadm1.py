#!/usr/bin/env python3

# Author: Adarsh Kumar
# GitHub/GitLab: @iamadarshk

T = int(input())

for test_case in range(T):
    n = int(input())
    A = [int(i) for i in input().split()]
    B = [int(i) for i in input().split()]
    A = [A[i]*20 - B[i]*10 for i in range(n)]
    print(max(max(A),0))

