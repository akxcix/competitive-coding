fact = [1]
for i in range(1,51):
    fact.append(i*fact[i-1])
t = int(input())
for testcase in range(t):
    n,k = [int(i) for i in input().split()]
    arr = [int(i) for i in input().split()]
    freq = [0 for i in range(101)]
    for num in arr:
        freq[num]+=1
    for num in range(101):
        if k > freq[num]:
            k -= freq[num]
        else:
            ans = int((fact[freq[num]])/((fact[k])*(fact[freq[num]-k])))
            print(ans)
            break

        