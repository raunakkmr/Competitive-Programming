import math
import string

t = int(input())
for tc in range(t):
    n, l = [int(x) for x in input().split()]
    vals = [int(x) for x in input().split()]
    g = math.gcd(vals[0], vals[1])
    primes = [vals[0] // g]
    for i in range(l):
        primes.append(vals[i] // primes[-1])
    sorted_primes = sorted(list(set(primes)))
    mapping = dict()
    for (i, ch) in enumerate(string.ascii_uppercase):
        mapping[sorted_primes[i]] = ch
    ans = ''
    for p in primes:
        ans += mapping[p]
    print("Case #{}: {}".format(tc+1, ans))