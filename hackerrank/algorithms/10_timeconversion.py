#!/bin/python3

import os
import sys

#
# Complete the timeConversion function below.
#
def timeConversion(s):
    #
    # Write your code here.
    H = int(s[0:2])
    # M = int(s[3:5])
    # S = int(s[7:9])
    if s[8]=='P':
        if H!=12:
            s=str(H+12)+s[2:8];
            return s
    elif s[8]=='A':
        if H==12:
            s="00"+s[2:8];
            return s
    return s[0:8];
    # s_seconds = S+M*60+H*3600
    # if s_seconds >= 12*3600:

    #


s = input()

result =     timeConversion(s)

print(result)
