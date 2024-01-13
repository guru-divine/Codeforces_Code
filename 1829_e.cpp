//Author: guru_divine
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mod 1000000007
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> mat(n, vi(m));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin >> mat[i][j];
        }
    }

    queue<pii> q;
    vector<vi> vis(n, vi(m, 0));
    ll maxi=0;

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            ll sum=0;

            if(!vis[i][j] && mat[i][j]) {
                q.push({i, j});
                vis[i][j]=1;
                int delRow[4] = {0,-1,0,1};
                int delcol[4] = {-1,0,1,0};

                while(!q.empty()) {
                    int row = q.front().first;
                    int col = q.front().second;
                    sum += mat[row][col];
                    q.pop();
                    for(int k=0; k<4; ++k) {
                        int nRow = row+delRow[k];
                        int nCol = col+delcol[k];
                        if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && mat[nRow][nCol] && !vis[nRow][nCol]) {
                            q.push({nRow, nCol});
                            vis[nRow][nCol]=1;
                        }
                    }
                }
            }

            maxi = max(maxi, sum);
        }
    }

    cout << maxi << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}