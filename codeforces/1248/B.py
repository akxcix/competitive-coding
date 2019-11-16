n = int(input())
arr = [int(i) for i in input().split()]
arr = sorted(arr)
count = n
hor =0
ver = 0
i = 0
j = n-1
while True:
    hor += arr[j]
    j -= 1
    count -= 1
    if count == 0:
        break
    ver += arr[i]
    i += 1
    count -= 1
    if count == 0:
        break
ans = hor**2 + ver**2
print(ans) 
