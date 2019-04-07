import math
import string

t = int(input())
mapping = dict()
for tc in range(t):
    mapping.clear()
    n, l = [int(x) for x in input().split()]
    vals = [int(x) for x in input().split()]
    start = -1
    for i in range(l-1):
        if vals[i] != vals[i+1]:
            start = i
            break
    g = math.gcd(vals[start], vals[start+1])
    primes = [0] * (l+1)
    primes[start] = vals[start] // g
    for i in range(start, l):
        primes[i+1] = vals[i] // primes[i]
    for i in reversed(range(start)):
        primes[i] = vals[i+1] // primes[i+1]
    # g = math.gcd(vals[0], vals[1])
    # primes = [vals[0] // g]
    # for i in range(l):
    #     primes.append(vals[i] // primes[-1])
    sorted_primes = sorted(list(set(primes)))
    for (i, ch) in enumerate(string.ascii_uppercase):
        mapping[sorted_primes[i]] = ch
    ans = ''
    for p in primes:
        ans += mapping[p]
    print("Case #{}: {}".format(tc+1, ans))