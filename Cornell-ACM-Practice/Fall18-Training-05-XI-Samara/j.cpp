#include <iostream>

using namespace std;

const int N = 2e5+5;
int cnt[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; cnt[x]++;
    }

    int tot = 0;
    for (int i = 0; i < N; i++) {
        tot += cnt[i];
        if (cnt[i]%2 == 1) tot--;
    }

    cout << tot / 4 << '\n';
}