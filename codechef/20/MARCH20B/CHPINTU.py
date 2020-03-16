t = int(input())

for testCase in range(t):
    n, m = [int(i) for i in input().split()]
    f = [int(i) for i in input().split()]
    p = [int(i) for i in input().split()]

    hmap = {}

    for i in range(n):
        hmap[f[i]] = hmap.setdefault(f[i], 0) + p[i]
    minimum = 5000000000000000000
    for key in hmap.keys():
        if hmap[key] < minimum:
            minimum = hmap[key]
    print(minimum)

