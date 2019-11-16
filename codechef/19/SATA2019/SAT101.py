T = int(input())
for testCase in range(T):
    s = input().strip()
    n = len(s)
    forwardhash = {}
    backwardhash = {}
    alphas = []
    for i in range(n):
        forwardhash[s[i]] = forwardhash.setdefault(s[i],i)
        alphas.append(s[i])
    for i in range(n-1,-1,-1):
        backwardhash[s[i]] = backwardhash.setdefault(s[i],i) 
    maxl = '-'
    maxpow = 0
    for alpha in alphas:
        l = alpha
        power = backwardhash[l] - forwardhash[l]
        if power > maxpow:
            maxpow = power
            maxl = l
        elif power == maxpow:
            if l<maxl:
                maxl = l
    print(maxl, maxpow)