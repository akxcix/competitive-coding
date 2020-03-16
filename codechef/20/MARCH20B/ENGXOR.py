t = int(input())

def parity(x): 
    y = x ^ (x >> 1) 
    y = y ^ (y >> 2) 
    y = y ^ (y >> 4) 
    y = y ^ (y >> 8) 
    y = y ^ (y >> 16) 
    if (y & 1): 
        return 1 
    return 0 

for testCase in range(t):
    n, q = [int(i) for i in input().split()]
    a = [parity(int(i)) for i in input().split()]
    odd = 0
    even = 0
    for ai in a:
        if ai == 1:
            odd +=1
        else:
            even += 1
    for query in range(q):
        p = parity(int(input()))
        qe = 0
        qo = 0
        if p == 1:
            qe = odd
            qo = even
        else:
            qe = even
            qo = odd
        print(qe, qo)

