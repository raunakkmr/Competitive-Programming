#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        double sd = stod(s);
        if (!s.compare("0") || !s.compare("0.0") || !s.compare("0.00") || !s.compare("0.000") || !s.compare("0.0000") || s[0] == '1') {
            cout << 1 << endl;
            continue;
        }
        int len = s.size()-2;
        int den = 1;
        while (len--) den *= 10;
        int num = stoi(s.substr(2, string::npos));
        int g = gcd(num, den);
        cout << den/g << '\n';
    }

}