def digitsum(N):
    N_str = str(N)
    sum = 0
    for digit in N_str:
        sum+=int(digit)
    return sum

def add(N,D):
    N = N + D
    return N

def mindigitsum(N):
    if (N == 0): 
        return 0
    if (N % 9 == 0): 
        return 9 
    else: 
        return (N % 9) 

T = int(input())
for TestCase in range(T):
    N,D = map(int,input().split())
    mindigitsum = N
    operations = 0

