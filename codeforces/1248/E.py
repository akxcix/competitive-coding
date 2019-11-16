n,p = [int(i) for i in input().split()]
t = [int(i) for i in input().split()]
arr = [[t[i],i] for i in range(n)]
arr.sort(key=lambda x: x[0])
ctime = 0
output = [0 for i in range(n)]
arrind = 0
ctime = arr[0][0]
done = 0
print(arr)
while True:
    flag = 0
    for i in range(arrind,n):
        if t[i] <= ctime:
            ctime += p
            output[i] = ctime
            flag = 1
            done -= 1
    if flag == 0:
        ctime = arr[arrind][0]
    if done == n:
        break

    
