#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <limits>

using namespace std;

#define int long long
typedef pair<int, int> pii;

const int S = 2e5+5;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int n, m, d;
string grid[S];
pii st, en;

#undef int
int main() {
    #define int long long
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) cin >> grid[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') continue;
            if (grid[i][j] == 'S') st = {i,j};
            if (grid[i][j] == 'F') en = {i,j};
        }
    }

    // vector<vector<int>> rowsum(n, vector<int>(m, 0));
    // vector<vector<int>> colsum(m, vector<int>(n, 0));
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         rowsum[i][j] = grid[i][j] == 'M';
    //         if (j != 0) rowsum[i][j] += rowsum[i][j-1];
    //     }
    // }
    // for (int j = 0; j < m; j++) {
    //     for (int i = 0; i < n; i++) {
    //         colsum[j][i] = grid[i][j] == 'M';
    //         if (i != 0) colsum[j][i] += colsum[j][i-1];
    //     }
    // }

    queue<pii> q1;
    vector<vector<int>> dist1(n, vector<int>(m, numeric_limits<int>::max()/100));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                dist1[i][j] = 0;
                q1.push({i,j});
            }
        }
    }
    while (!q1.empty()) {
        auto cur = q1.front();
        q1.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first+dx[i], ny = cur.second+dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist1[nx][ny] < numeric_limits<int>::max()/100) continue;
            dist1[nx][ny] = 1 + dist1[cur.first][cur.second];
            q1.push({nx,ny});
        }
    }

    queue<pii> q2;
    vector<vector<int>> dist2(n, vector<int>(m, numeric_limits<int>::max()/100));
    dist2[st.first][st.second] = 0;
    q2.push(st);
    while (!q2.empty()) {
        auto cur = q2.front();
        q2.pop();
        if (dist1[cur.first][cur.second] <= d) continue;
        for (int i = 0; i < 4; i++) {
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist1[nx][ny] <= d) continue;
            if (dist2[nx][ny] < numeric_limits<int>::max()/100) continue;
            if (grid[nx][ny] == 'M') continue;
            // int tmp = 0;
            // tmp = max(0LL, nx-d);
            // if (colsum[ny][nx] - colsum[ny][tmp] > 0 || grid[tmp][ny] == 'M') continue;
            // tmp = min(nx+d, n-1);
            // if (colsum[ny][tmp] - colsum[ny][nx] > 0 || grid[nx][ny] == 'M') continue;
            // tmp = max(0LL, ny-d);
            // if (rowsum[nx][ny] - rowsum[nx][tmp] > 0 || grid[nx][tmp] == 'M') continue;
            // tmp = min(ny+d, m-1);
            // if (rowsum[nx][tmp] - rowsum[nx][ny] > 0 || grid[nx][ny] == 'M') continue;

            dist2[nx][ny] = 1 + dist2[cur.first][cur.second];
            q2.push({nx, ny});
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (grid[i][j] != 'M') continue;
    //         if (dist2[i][j] < numeric_limits<int>::max()/100) {
    //             cout << "NO\n"; return 0;
    //         }
    //     }
    // }
    if (dist2[en.first][en.second] == numeric_limits<int>::max()/100) {
        cout << -1 << '\n';
    } else {
        cout << dist2[en.first][en.second] << '\n';
    }
}