#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll n, k;
vector<string> v, parts;
string tstr;

struct tn {
  bool isleaf;
  tn *children[26];

  tn() {
    isleaf = false;
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
  }
};

const int MAXN = 1e6+5;
ll bit[MAXN+1];

ll query(ll x) {
  ll sum = 0;
  while (x > 0) {
    sum += bit[x]; x -= (x & -x);
  }
  return sum;
}

void add(ll x, ll val) {
  while (x <= MAXN) {
    bit[x] += val;
    x += (x & -x);
  }
}

ll gr(const string &s) {
  auto it = lower_bound(v.begin(), v.end(), s);
  ll ra = it - v.begin();
  add(ra+1, 1);
  return ra - query(ra);
}

void insert(tn *root, const string &s) {
  tn *cur = root;
  for (const char &ch : s) {
    int i = ch - 'a';
    if (cur->children[i] == NULL) {
      cur->children[i] = new tn();
    }
    cur = cur->children[i];
  }
  cur->isleaf = true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  cin >> tstr;

  // sort the input strings
  sort(v.begin(), v.end());

  // insert strings into trie for fast segmentation
  tn *root = new tn();
  for (const string &s : v) {
    insert(root, s);
  }

  // segment test string into individual parts
  tn *cur = root;
  ll len = 0;
  for (int i = 0; i < tstr.size(); i++) {
    // cout << i << " " << len << " " << tstr.substr(i-len, len) << endl;
    if (cur->isleaf) {
      parts.push_back(tstr.substr(i-len, len));
      cur = root;
      len = 0;
    }
    len++;
    int pos = tstr[i] - 'a';
    cur = cur->children[pos];
    if (i == tstr.size()-1) {
      parts.push_back(tstr.substr(i+1-len, len));
      cur = root;
      len = 0;
    }
  }

  // cout << tstr << endl;
  // for (const auto &s : parts) cout << s << " "; cout << endl;

  ll ans = (gr(parts[0]) + 1) % MOD;
  for (int i = 1; i < parts.size(); i++) {
    ll tmp = ((ans-1) * (n-i)) % MOD;
    ans = (tmp + gr(parts[i]) + 1) % MOD;
    ans = (ans + MOD) % MOD;
  }

  cout << ans << endl;

}
