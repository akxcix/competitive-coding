t = int(input())
for testcase in range(t):
    n = int(input())
    c = [int(i) for i in input().split()]
    h = [int(i) for i in input().split()]
    h = sorted(h)
    sumarr = [0 for i in range(n)]
    for i in range(n):
        if i - c[i] > 0:
            sumarr[i - c[i]] += 1
        else:
            sumarr[0] += 1
        if (i + c[i] + 1) < n:
            sumarr[i + c[i] + 1] -= 1
    arr = []
    arr.append(sumarr[0])
    for i in range(1, n):
        sumarr[i] += sumarr[i - 1]
        arr.append(sumarr[i])
    arr = sorted(arr)
    flag = 7265
    for i in range(n):
        if arr[i] != h[i]:
            flag = 9823
            break
    if flag == 9823:
        print("NO")
    else:
        print("YES")
