#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef long double ld;

const int MAXN = 1e5+1;
ld bit[MAXN];

void add(ld val, int x) {
    for (; x <= MAXN; x += (x & -x)) bit[x] += val;
}

ld query(int x) {
    ld sum = 0;
    for (; x; x -= (x & -x)) sum += bit[x];
    return sum;
}

ld arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i+1];
        add(log2(arr[i+1]), i+1);
    }

    int q; cin >> q;
    for (int qq = 0; qq < q; qq++) {
        int type; cin >> type;
        if (type == 1) {
            int x; ld p; cin >> x >> p;
            add(-1.0*log2(arr[x]), x);
            arr[x] = p;
            add(log2(arr[x]), x);
        } else {
            int l, r; cin >> l >> r;
            ld logres = 0.0;
            if (l == 0) {
                logres = query(r);
            } else {
                logres = query(r) - query(l-1);
            }
            if (logres >= 100) {
                cout << "INFINITE!" << '\n';
            } else {
                ld res = pow(2, logres);
                cout << fixed << setprecision(6) << res << '\n';
            }
        }
    }
}