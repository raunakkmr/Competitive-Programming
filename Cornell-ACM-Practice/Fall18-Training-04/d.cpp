#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long double ld;

const ld EPS = 1e-8;
const int N = 1e5+5;

struct st {
    int id;
    int c;
    ld r;

    st() {}
    st(int i, int a, ld b) : id(i), c(a), r(b) {}
};

bool cmp(const st &f, const st &s) {
    ld left = f.c - s.c;
    ld right = f.c*s.r - s.c*f.r;
    if (abs(left-right) < EPS) return f.id < s.id;
    else return left < right;

}

st arr[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, w; cin >> n >> w;
    ld wd = w;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].c >> arr[i].r;
        arr[i].id = i;
    }
    sort(arr, arr+n, cmp);
    ld ans = 0.0;
    for (int i = 0; i < n; i++) {
        ans += arr[i].c*wd;
        wd *= arr[i].r;
    }
    cout << fixed << setprecision(6) << ans << '\n';
}