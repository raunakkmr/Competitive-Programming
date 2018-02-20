#include<bits/stdtr1c++.h>

using namespace std;

int n;
int arr[101][101];
int minx, miny, maxx, maxy;


int solve() {
  if (maxx-minx > maxy-miny)
    return pow(maxx-minx,2);
  else
    return pow(maxy-miny,2);
}

int main() {
  memset(arr, -1, sizeof arr);
  cin >> n;
  minx = 1000, miny = 1000;
  maxx = -1;
  maxy = -1;
  for (int i=0; i<n; i++) {
    int x, y;
    cin >> x >> y;
    arr[x][y] = 1;
    if (x < minx) minx = x;
    if (y < miny) miny = y;
    if (x > maxx) maxx = x;
    if (y>maxy) maxy = y;
  }
  cout << solve() << endl;
  return 0;
}
