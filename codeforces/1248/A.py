t = int(input())
for testCase in range(t):
    n = int(input())
    p = [int(i) for i in input().split()]
    m = int(input())
    q = [int(i) for i in input().split()]
    count = 0
    # for i in p:
    #     for j in q:
    #         if (abs(i+j)%2 == 0) and (abs(i-j)%2 == 0):
    #             count +=1
    evenp = 0
    evenq = 0
    oddp=0
    oddq=0
    for i in p:
        if i%2==0:
            evenp +=1
        else:
            oddp+=1
    for j in q:
        if j%2==0:
            evenq+=1
        else:
            oddq+=1
    count = (evenp*evenq)+(oddp*oddq)
    print(count)