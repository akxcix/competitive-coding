#!/usr/bin/env python3

# Author: Adarsh Kumar
# GitHub/GitLab: @iamadarshk

T = int(input())

for test_case in range(T):
    n, k = [int(i) for i in input().split()]
    c = int(n/k)
    if c%k==0:
        print('NO')
    else:
        print('YES')

