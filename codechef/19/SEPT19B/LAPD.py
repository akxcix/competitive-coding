MOD = 1000000007
t = int(input())
for testcase in range(t):
    A,B,C = [int(i) for i in input().split()]
    ans = 0
    for b in range(B+1):
        term1 = A-b
        term2 = C-b-1
        term3 = A-b-1
        if term1 < 0 or term2 < 0 or term3 < 0:
            continue
        temp = term1 * term2 + term3
        ans += temp%MOD
    print(ans)









# sum += a-b * c-b-1
# + a-b-1