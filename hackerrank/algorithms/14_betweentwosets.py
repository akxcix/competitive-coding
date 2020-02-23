#!/bin/python3

import math
import os
import random
import re
import sys
import functools

#
# Complete the 'getTotalX' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER_ARRAY b

def LCM(a,b):
    return abs(a*b) // math.gcd(a,b)

def getTotalX(a, b):
    # Write your code here
    gcd = functools.reduce(math.gcd, b)
    lcm = functools.reduce(LCM,a)

    count = 0
    n = int(gcd/lcm)
    for i in range(1,n+1):
        if gcd % (lcm*i) == 0:
            count += 1

    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))

    brr = list(map(int, input().rstrip().split()))

    total = getTotalX(arr, brr)

    fptr.write(str(total) + '\n')

    fptr.close()

