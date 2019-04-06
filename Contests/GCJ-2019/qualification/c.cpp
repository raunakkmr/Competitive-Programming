#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef long long ll;

const ll N = 1e4+5;
const ll L = 105;
bool prime[N];
ll vals[L];

void sieve(ll n) {
    memset(prime, true, sizeof prime);
    for (ll p = 2; p*p <= n; p++) {
        if (prime[p]) {
            for (ll i = p*2; i <= n; i+=p) prime[i] = false;
        }
    }
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve(N);
    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        memset(vals, 0, sizeof vals);
        ll n, l; cin >> n >> l;
        for (ll i = 0; i < l; i++) cin >> vals[i];
        cout << "Case #" << tc << ": ";
        vector<ll> pp;
        set<ll> pps;
        for (ll i = 0; i < l-1; i++) {
            ll a = vals[i], b = vals[i+1];
            ll g = gcd(a, b);
            if (i == 0) {
                pp.push_back(vals[0]/g);
                pps.insert(vals[0]/g);
            }
            pp.push_back(g);
            pps.insert(g);
            if (i == l-2) {
                pp.push_back(vals[l-1]/g);
                pps.insert(vals[l-1]/g);
            }
        }
        vector<ll> spp(pps.begin(), pps.end());
        ll len = pp.size();
        ll idx = -1;
        string res = "";
        for (ll i = 0; i < len; i++) {
            idx = lower_bound(spp.begin(), spp.end(), pp[i]) - spp.begin();
            res += 'A'+idx;
        }
        cout << res;
        cout << endl;
    }
}