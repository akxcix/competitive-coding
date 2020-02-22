t = int(input())
for test_case in range(t):
    n = int(input())
    arr = [int(i) for i in input().split()]
    total = sum(arr)
    avg = total/n
    flag = 0
    for i in range(n):
        if avg == (total-arr[i])/(n-1):
            print(i+1)
            flag=1
            break
    if flag==0:
        print('Impossible')
