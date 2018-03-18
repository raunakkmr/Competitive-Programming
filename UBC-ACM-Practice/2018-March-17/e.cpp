#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
  int N;
  vector<vector<Edge> > G;
  vector<LL> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  void Enqueue(int v) { 
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); } 
  }

  void Push(Edge &e) {
    int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;    
    excess[e.from] -= amt;
    Enqueue(e.to);
  }

  void Gap(int k) {
    for (int v = 0; v < N; v++) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (int i = 0; i < G[v].size(); i++) 
      if (G[v][i].cap - G[v][i].flow > 0)
        dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1) 
        Gap(dist[v]); 
      else
        Relabel(v);
    }
  }

  LL GetMaxFlow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }

    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }

    LL totflow = 0;
    for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }
};

int dx[] = {0,0,1,0,-1};
int dy[] = {0,1,0,-1,0};
int field[105][105];

int main() {
  int s = 0, t = 1;
  int nv = 0, n, k, h;
  cin >> n >> k >> h;
  nv = 2 + (h+1)*2*n*n;
  PushRelabel pr = PushRelabel(nv);
  memset(field, 0, sizeof field);
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cin >> field[i][j];
    }
  }
  vector<pii> cows(k);
  for (int i=0; i<k; i++) {
    cin >> cows[i].first >> cows[i].second;
  }
  vector<int> rain(h);
  for (int i=0; i<h; i++) {
    cin >> rain[i];
  }
  for (int i=0; i<k; i++) {
    int u = 2 + (cows[i].first*n+cows[i].second);
    pr.AddEdge(s,u,1);
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      for (int hr=0; hr<=h; hr++) {
        int vin = 2 + (i*n+j) + (hr*n*n*2);
        int vout = vin + (n*n);
        pr.AddEdge(vin,vout,1);
        if (hr < h) {
          for (int d=0; d<5; d++) {
            int y = j+dy[d];
            int x = i+dx[d];
            int vin2 = 2 + ((hr+1)*n*n*2) + (x*n+y);
            if (x>=0 && y>=0 && x<n && y<n && field[x][y]>rain[hr]) {
              pr.AddEdge(vout,vin2,1);
            }
          }
        }
        else {
          if (field[i][j] > rain[hr-1]) {
            pr.AddEdge(vout,t,1);
          }
        }
      }
    }
  }
  LL flow = pr.GetMaxFlow(s,t);
  cout << flow << endl;
}
