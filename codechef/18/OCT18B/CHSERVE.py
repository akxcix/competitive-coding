T = int(input())
for TestCase in range(T):
    p1,p2,k = map(int,input().split())
    if int((p1+p2)/k)%2==0:
        print('CHEF')
    else:
        print('COOK')

