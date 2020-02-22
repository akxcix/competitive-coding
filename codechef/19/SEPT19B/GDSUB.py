import functools
mod = 1000000007

functools.lru_cache(maxsize=None)
def nGoodSequences(fmap, k, i, keys):
    if(k == 0 or i == len(keys)):
        return 1
    inc = fmap[keys[i]] * nGoodSequences(fmap, k - 1, i + 1, keys)
    exc = nGoodSequences(fmap, k, i + 1, keys)
    return (inc + exc) % mod

n , k = [int(i) for i in input().split()]
A = [int(i) for i in input().split()]
fre_map = {}
for i in A:
    fre_map[i] = fre_map.setdefault(i, 0) + 1
print(nGoodSequences(fre_map, k, 0, list(fre_map.keys())))