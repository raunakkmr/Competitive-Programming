#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>
#include <utility>
#include <cmath>

using namespace std;

#define endl '\n'
typedef long double ld;
typedef pair<ld, ld> pdd;

int n, k;
ld ans;
vector<int> idx;
vector<pdd> pts;
int num_samples = (int)1e7;

ld ComputeArea() {
    ld res = 0;
    for (int i = 0; i < k-1; i++) {
        // cout << idx[i] << endl;
        res += (pts[idx[i]].first*pts[idx[i+1]].second - pts[idx[i]].second*pts[idx[i+1]].first);
    }
    res += (pts[idx[k-1]].first*pts[idx[0]].second - pts[idx[k-1]].second*pts[idx[0]].first);
    return abs(res) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    pts.resize(n);
    idx.resize(k);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].first >> pts[i].second;
    }
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = i;
    }

    for (int i = 0; i < num_samples; i++) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = i;
        }
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(v.begin(), v.end(), default_random_engine(seed));
        for (int j = 0; j < k; j++) {
            idx[j] = v[j];
        }
        sort(idx.begin(), idx.end());
        ans += ComputeArea();
    }
    cout << fixed << setprecision(6) << ans / num_samples << endl;
}