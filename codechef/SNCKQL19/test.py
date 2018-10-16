import random
T = 1000
print(T)
for testcase in range(T):
    N = 10**4
    K = 10**3
    print(N,K)
    for i in range(N):
        print(random.randint(1,10**4),end=' ')
    print('')
