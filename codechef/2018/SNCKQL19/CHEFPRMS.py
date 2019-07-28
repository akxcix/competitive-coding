import math
def primefact(num):
    count = 0
    factors=[]
    while num%2==0:
        num /=2
        factors.append(2)
        count +=1
    for i in range(3,int(math.sqrt(num))+1,2):
        while num%i==0:
            num /=i
            factors.append(i)
            count +=1
    if num>2:
        count +=1
        factors.append(num)
    return (count,factors)
T = int(input())
for testcase in range(T):
    N = int(input())
    flag = 0
    for semi in range(1,int(N/2)+1):
        if primefact(N-semi)[0]==2 and primefact(semi)[0]==2 and primefact(semi)[1][0]!=primefact(semi)[1][1] and primefact(N-semi)[1][0]!=primefact(N-semi)[1][1]:
            flag +=1
            break
    if flag==1:
        print('YES')
    else:
        print('NO')
