def splitter(N):
    a=0
    b=N
    while a<N:
        b = N-a
        if ('4' in str(a)) or ('4' in str(b)):
            a+=1
            continue
        else:
            return a,b

def str_splitter(N):
    N = list(str(N))
    a = N.copy()
    b = N.copy()
    for i in range(len(N)):
        if N[i] == '4':
            a[i] ='3'
            b[i] = '1'
        else:
            b[i] = '0'

    a = int(''.join(a))
    b = int(''.join(b))
    return a,b




T = int(input())
for testCase in range(T):
    N = int(input())
    a,b = str_splitter(N)
    print('Case #'+str(testCase+1)+':',a,b)
