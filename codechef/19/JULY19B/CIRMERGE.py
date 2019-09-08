t = int(input())
for test_case in range(t):
    n = int(input())
    arr = [int(i) for i in input().split()]
    arr = sorted(arr,reverse=True)
    s = sum(arr)
    s1 = s
    s2 = 0
    for i in range(n-1):
        s2 = s2+arr[i]
        s1 = s1 + s-s2
        print('s1:',s1,'s1:',s2,arr[i])

    print(s1)