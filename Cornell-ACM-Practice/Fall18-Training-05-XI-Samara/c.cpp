#include <iostream>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

struct ev {
    int id, val, type;  // type 0 - start, 1 - end

    ev() {}
    ev(int a, int b, int c) : id(a), val(b), type(c) {}
};

struct cmp {
    bool operator()(const ev &a, const ev &b) const {
        if (a.val < b.val) return true;
        if (a.val > b.val) return false;
        if (a.type < b.type) return true;
        if (a.type > b.type) return false;
        return a.id < b.id;
    }
};

int n;
set<ev, cmp> events;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        events.insert({i, a, 0});
        events.insert({i, b, 1});
    }

    set<int> done;
    set<int> pending;
    set<int> ans;
    while (!events.empty()) {
        auto cur = *events.begin();
        events.erase(events.begin());
        if (done.find(cur.id) != done.end()) continue;
        if (cur.type == 0) {
            pending.insert(cur.id);
        } else if (cur.type == 1) {
            ans.insert(cur.val); 
            for (const auto &x : pending) {
                done.insert(x);
            }
            pending.clear();
        }
    }

    cout << ans.size() << '\n';
    for (const int &x : ans) {
        cout << x << " ";
    }
    cout << '\n';

}