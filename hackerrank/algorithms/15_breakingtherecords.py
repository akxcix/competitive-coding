#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the breakingRecords function below.
def breakingRecords(scores):
    lowest = scores[0]
    highest = scores[0]
    mincount = 0
    maxcount = 0
    for score in scores:
        if score > highest:
            highest = score
            maxcount += 1
        elif score < lowest:
            lowest = score
            mincount += 1
    return(maxcount, mincount)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    scores = list(map(int, input().rstrip().split()))

    result = breakingRecords(scores)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
