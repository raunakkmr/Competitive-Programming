#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;
    string str; getline(cin, str);
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        string ans = "";
        for (char c : str) {
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                bool upper = (c >= 'A' && c <= 'Z');
                long long code = upper? c-'A' : c-'a';
                long long new_code = (code - s + 26000000000) % 26;
                // cerr << upper << " " << code << " " << new_code << '\n';
                char new_c = upper? (int)new_code+'A' : (int)new_code+'a';
                cout << new_c;
            } else {
                cout << c;
            }
        }
        cout << '\n';
    }
}