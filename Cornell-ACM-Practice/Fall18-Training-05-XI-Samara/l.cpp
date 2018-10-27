#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string p = "";
map<char, vector<int>> m;
vector<int> hist;

bool f(char c) {
    int poss = -1;
    if (hist.size() != 0) poss = hist[hist.size()-1];
    if (poss == -5) {
        hist.push_back(-5);
        return false;
    }
    auto pos = upper_bound(m[c].begin(), m[c].end(), poss);
    if (pos == m[c].end()) {
        hist.push_back(-5);
        return false;
    }
    hist.push_back(*pos);
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        m[s[i]].push_back(i);
    }

    int q; cin >> q;
    string op = "";
    char c;
    for (int i = 0; i < q; i++) {
        cin >> op;
        if (op == "push") {
            cin >> c;
            p += c;
            if (f(c)) cout << "YES\n";
            else cout << "NO\n";
        } else {
            p = p.substr(0, p.size()-1);
            hist.pop_back();
            if (hist.size() == 0) cout << "YES\n";
            else if (hist[hist.size()-1] == -5) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}