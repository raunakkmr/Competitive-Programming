#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <bitset>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

const int SZ = 15;

int n, m, si, sj, smask, len, ei, ej;
int d[15][15][(1<<17)];
bool seen[15][15][(1<<17)];
vector<pii> pos(10);
string grid[SZ];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int ssi, int ssj, int smask) {
    memset(d, 0x3f3f3f3f, sizeof d); memset(seen, 0, sizeof seen);
    d[ssi][ssj][smask] = 0; seen[ssi][ssj][smask] = true;
    queue<pipii> q; q.push({smask,{ssi,ssj}});
    while(!q.empty()) {
        int mask = q.front().first;
        pii cur = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ni = cur.first+dx[i], nj = cur.second+dy[i];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            if (grid[ni][nj] == '#') continue;
            int ti = cur.first, tj = cur.second;
            int tmask = mask, nmask = (mask << 2) & ((1 << (2*len-1)) - 1);
            bool is_occupied = false, is_last = false;
            int num_occupied = 0;
            for (int j = 0; j+1 < len; j++) {
                int cur_offset = tmask & 3;
                tmask = tmask >> 2;
                ti += dx[cur_offset]; tj += dy[cur_offset];
                is_occupied |= (ti == ni && tj == nj);
                num_occupied += (ti == ni && tj == nj);
            }
            is_last = (ti == ni && tj == nj);
            if (is_occupied && !is_last) continue;
            int noffset = mask & 3;
            if (noffset == i) continue;
            if (noffset <= 1 && i <= 1) nmask |= noffset;
            if (noffset <= 1 && i == 2) nmask |= 3;
            if (noffset <= 1 && i == 3) nmask |= 2;
            if (noffset >= 2 && i >= 2) nmask |= noffset;
            if (noffset >= 2 && i == 0) nmask |= 1;
            if (noffset >= 2 && i == 1) nmask |= 0;
            int num = grid[ni][nj] - '0';
            if (grid[ni][nj] == '.' || grid[ni][nj] == '@' || is_last || (num > 0 && num <= 9 && !is_occupied)) {
                if (seen[ni][nj][nmask]) continue;
                seen[ni][nj][nmask] = true;
                d[ni][nj][nmask] = 1 + d[cur.first][cur.second][mask];
                q.push({nmask,{ni,nj}});
            }
            // if (cur.first == 11 && cur.second == 13 && ni==11 && nj==14) {
            //     bitset<16> bs1(mask), bs2(nmask);
            //     cerr << bs1.to_string() << " " << bs2.to_string() << endl;
            //     if (bs1.to_string() == "1001011111000010") {
            //         cerr << cur.first << " " << cur.second << endl;
            //         cerr << ti << " " << tj << endl;
            //         cerr << num_occupied << " " << is_last << endl;
            //         cerr << grid[ni][nj] << " " << num << " " << is_occupied << endl;
            //     }
            // }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> grid[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '@') {
                ei = i, ej = j;
            }
            if (grid[i][j] == '1') {
                si = i, sj = j;
            }
            int num = grid[i][j]-'0';
            if (num >= 0 && num <= 9) {
                len = max(len, num);
                pos[num] = {i,j};
            }
        }
    }

    // 00 - up, 01 - down, 10 - left, 11 - right
    for (int i = 2; i <= len; i++) {
        int tmp = 0;
        if (pos[i].first == pos[i-1].first-1) tmp = 0;
        else if (pos[i].first == pos[i-1].first+1) tmp = 1;
        else if (pos[i].second == pos[i-1].second-1) tmp = 2;
        else if (pos[i].second == pos[i-1].second+1) tmp = 3;
        smask |= (tmp << (2*(i-2)));
    }

    bfs(si, sj, smask);

    int ans = 0x3f3f3f3f;
    for (int i = 0; i < (1<<(17)); i++) {
        ans = min(ans, d[ei][ej][i]);
    }

    if (ans < 0x3f3f3f3f) cout << ans << '\n';
    else cout << -1 << '\n';
}