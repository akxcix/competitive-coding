#!/usr/bin/env python3

# Author: Adarsh Kumar
# GitHub/GitLab: @iamadarshk
def solve(s):
    count = s.count('1')
    if count%2==0:
        return False
    if count%2==1:
        return True


T = int(input())

for test_case in range(T):
    s = list(input())
    ans = solve(s)
    if ans == True:
        print('WIN')
    else:
        print('LOSE')

