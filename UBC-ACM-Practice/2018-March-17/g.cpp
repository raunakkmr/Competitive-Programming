#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1400;
const int INF = numeric_limits<int>::max()/1000;

//*/
//! w[i][j] = weight of edge from i on left side to j on right side
//! ml[i]   = matching of left vertex i
//! mr[i]   = matching of right vertex j
//! lbl[i]  = score of left vertex i
//! lbr[j]  = score of right vertex j
int w[N][N], ml[N], mr[N], lbl[N], lbr[N], s[N], slack[N], par[N]; // Yury's
//! Run time is O(m * n^2)
int wmatch(int n, int m){ // assume n <= m;
  int i, j, k, done, al, nxt, out = 0;
  //!
  //! Set lbl[i] = max{w[i][j]} over j
  //! Set lbr[j] to 0
  //! This creates an admissible labeling:
  //! For all i, j, w[i][j] <= lbl[i] + lbr[j]
  //! Throughout the algorithm, the labeling will be admissible
  for(i=0;i<n;i++)for(j=0,lbl[i]=0,ml[i]=-1;j<m;j++) lbl[i]=max(lbl[i],w[i][j]);
  for(i = 0; i < m; i++) lbr[i] = 0, mr[i] = -1;
  //!
  //! Greedily find some (initial) matching
  //! such that if edge i->j is in the matching
  //! then w[i][j] = lbl[i] + lbr[j]
  //! This will also remain true throughout the algorithm
  for(i=0;i<n;i++) for(j = 0; j < m; j++) if(w[i][j] == lbl[i] && mr[j] == -1)
    { ml[i] = j, mr[j] = i; break; }
  //!
  //! for every unmatched left vertex i
  for(i = 0; i < n; i++) if(ml[i] == -1){
    //!
    //! Initialize S = {i}, T = {}
    //! S and T together describes a tree of alternating paths
    //! starting at vertex i, with every other edge
    //! part of the current matching
    //!
    //! Our goal is to extend this tree until it ends
    //! at an un-matched vertex j, and then we can
    //! flip every other edge in path to obtain a bigger matching
    //!
    //! We want to do this while keeping these properties true:
    //! (1) for all edges, w[i][j] <= lbl[i] + lbr[j]
    //! (2) if i->j is in matching, then w[i][j] = lbl[i] + lbr[j]
    //! (3) for every edge in the tree, w[i][j] = lbl[i] + lbr[j]
    //!     (this ensures (2) is still true, when we augment matching)
    //! Then when we get a maximum matching, it will be maximum weight
    //!
    //! s[i]   = 1   if i in S
    //!          0   if i not in S
    //! par[j] = -1  if j not in T
    //!        = i   if j is in T, and j's neighbor is i in S
    //!              meaning w[i][j] = lbl[i] + lbr[j]
    //!
    //! We initialize S = {i} and compute
    //! slack[j] = min { i in S } ( lbl[i] + lbr[j] - w[i][j] )
    for(j=0;j<m;j++) s[j]=(j==i), slack[j]=(lbl[i]+lbr[j]-w[i][j]), par[j] = -1;
    for(done = 0; !done;){
      //!
      //! al = min { j not in T } slack[j]
      for(j = 0, al = INF; j < m; j++) if(par[j] == -1) al = min(al, slack[j]);
      //!
      //! Transfer some labels from left to right like so:
      //! for i in S, lbl[i] -= al
      //! for j in T, lbr[j] += al
      //! modify slack[j] accordingly
      //!
      //! This forces slack[j] = 0 for some j not in T
      //! But keeps the admissible property: w[i][j] <= lbl[i] + lbr[j]
      //! (i.e. we create at least 1 neighbor of S that's not in T)
      for(j = 0, lbl[j] -= s[j]*al; j < m; ++j, lbl[j] -= s[j]*al)
        if(par[j] != -1) lbr[j] += al; else slack[j] -= al;
      //!
      //! Find a neighbor of S that is not in T, call it j
      //! Note the body of the if only runs once and breaks
      for(j = 0; j < m; j++) if(!slack[j] && par[j] == -1){
        //!
        //! find which i in S is a neighbor of j
        for(k=0;k<n;k++) if(s[k]&&(lbl[k]+lbr[j]==w[k][j])){ par[j] = k; break;}
        //!
        //! if j is not matched, then we found an augmented path, update matching
        if(mr[j] == -1){ done = 1;
          do{ nxt=ml[par[j]], mr[j]=par[j], ml[par[j]]=j, j=nxt;}while(j != -1);
        //!
        //! otherwise add j to T, and mr[j] to S, to extend alternating tree
        //! and update slacks accordingly
        }else for(k = 0, s[mr[j]] = 1; k < m; k++)
          slack[k] = min(slack[k], lbl[mr[j]] + lbr[k] - w[mr[j]][k]); break;}}}
  //!
  //! sum up the weight of matching
  for(i = 0; i < n; i++) out += w[i][ml[i]]; return out; }
//*!

int n, m;

int sat[3][4] = {{4,3,2,1},{8,7,6,5},{12,11,10,9}};

#undef int
int main() {
#define int long long
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> n >> m && n != 0 && m != 0) {
    memset(w, 0, sizeof w);
    int np = 0;
    vector<int> positions, pre;
    pre.push_back(0);
    for (int i = 0; i < n; i++) {
      int p; cin >> p; positions.push_back(p); np += p;
      pre.push_back(np);
    }
    for (int i = 0; i < m; i++) {
      int y, c1, c2, c3, c4;
      cin >> y >> c1 >> c2 >> c3 >> c4;
      y--;
      for (int ii = 0; ii < positions[c1]; ii++) {
        w[i][pre[c1]+ii] = 1 * sat[y][0];
      }
      for (int ii = 0; ii < positions[c2]; ii++) {
        w[i][pre[c2]+ii] = 1 * sat[y][1];
      }
      for (int ii = 0; ii < positions[c3]; ii++) {
        w[i][pre[c3]+ii] = 1 * sat[y][2];
      }
      for (int ii = 0; ii < positions[c4]; ii++) {
        w[i][pre[c4]+ii] = 1 * sat[y][3];
      }
    }
    // for (int i = 0; i < m; i++) {
    //   for (int j = 0; j < np; j++) {
    //     cout << w[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    cout << wmatch(m, np) << endl;
    // for (int i = 0; i < m; i++) cout << ml[i] << " "; cout << endl;
  }
}
