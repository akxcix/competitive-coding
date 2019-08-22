t = int(input())
for testcase in range(t):
    n = int(input())
    arr = [int(i) for i in input().split()]
    count = 0
    pair = []
    for i in range(n-1):
        xor = 0
        for k in range(i, n):
            xor = xor ^ arr[k]
            if xor == 0:
                pair.append([i, k])
    for i in pair:
        count += i[1] - i[0]
    print(count)
            
