import math

t = int(input())
for testcase in range(t):
    n,m = [int(i) for i in input().split()]
    maxm = ((n * (n-1))/2) + n
    if (m <  n-1 or m > maxm):
        print(-1)
    elif (n==1):
        print(m)
    elif (n==2 and m==1):
        print(1)
    elif (m <= n+1):
        print(2)
    elif (m <= 2*n):
        print(3)
    else:
        m -= 2*n
        print(3+int(math.ceil(m/(n/2))))