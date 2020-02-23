#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the migratoryBirds function below.
def migratoryBirds(arr):
    seta = set(arr)
    maxcount = 0
    maxid = 0
    for i in seta:
        if arr.count(i) > maxcount:
            maxcount = arr.count(i)
            maxid = i
        elif arr.count(i) == maxcount:
            if i < maxid:
                maxid = i
    return maxid 
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr_count = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = migratoryBirds(arr)

    fptr.write(str(result) + '\n')

    fptr.close()

