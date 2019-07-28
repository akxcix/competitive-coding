T = int(input())
for TestCase in range(T):
    N = int(input())-1
    x = N//26
    m = 2**x
    b,n,B = 0,0,0
    y = N%26
    if y <2:
        b = 1
    elif y <10:
        n = 1
    else:
        B = 1
    print(m*b,m*n,m*B)
