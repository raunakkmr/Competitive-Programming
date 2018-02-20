#include<bits/stdtr1c++.h>

using namespace std;

typedef long long ll;

ll n, k;
string word; int length;
ll arr[26][1000001];
ll counts[26];

ll solve(ll a, char c) {
  ll repeats, prefix, suffix;
  if (a%2==0)
    prefix = (((a/2)%length) * ((a-1)%length))%length;
  else
    prefix = ((((a-1)/2)%length) * (a%length))%length;
  repeats = 0;
  suffix = prefix + a;
  if (length-prefix <= a) {
    repeats = 1+(a-(length-prefix))/length;
    suffix = a - (length-prefix) - (repeats-1)*length;
  }
  int ch = c-'A';
  return arr[ch][length]*repeats + arr[ch][suffix] - arr[ch][prefix];
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  cin >> word; length = word.length();
  memset(arr, 0, sizeof arr);
  memset(counts, 0, sizeof counts);
  for (int i=0; i<length; i++) {
    counts[word[i]-'A']++;
    for (int j=0; j<26; j++) {
      arr[j][i+1] = counts[j];
    }
  }
  cin >> k;
  for (int i=0; i<k; i++) {
    ll a; char c;
    cin >> a >> c;
    cout << solve(a,c) << '\n';
  }
  return 0;
}
