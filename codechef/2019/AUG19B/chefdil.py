#!/usr/bin/env python3

# Author: Adarsh Kumar
# GitHub/GitLab: @iamadarshk
def solve(s):


T = int(input())

for test_case in range(T):
    s = list(input())
    s = [int(i) for i in s]
    ans = solve(s)
    if ans == True:
        print('WIN')
    else:
        print('LOSE')

