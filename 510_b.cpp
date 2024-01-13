//Author: DIVYA RAJ
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define nl "\n"
#define pb push_back
#define popb pop_back
#define F first
#define S second
#define sz(arr) arr.size()
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define mapi map<int, int>
#define un_mapi unordered_map<int, int>
#define mod 1000000007
#define fori(i,a,b) for(int i=a; i<b; ++i)
#define ford(i,a,b) for(int i=a; i>=b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reversei(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    vector<vi> vis(n, vi(m, 0));
    vector<vi> par(n, vi(m, -1));

    fori(i, 0, n) {
        fori(j, 0, m) {
            cin >> mat[i][j];
        }
    }
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    queue<pii> q;

    fori(i, 0, n) {
        fori(j, 0, m) {
            if(!vis[i][j]) {
                vis[i][j]=1;
                q.push({i, j});
                par[i][j] = i+100*j;

                while(!q.empty()) {
                    int x = q.front().F;
                    int y = q.front().S;
                    vis[x][y]=1;
                    q.pop();

                    fori(k, 0, 4) {
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                        if(mat[nx][ny]==mat[x][y]) {
                            if(!vis[nx][ny]) {
                                vis[nx][ny]=1;
                                q.push({nx, ny});
                                par[nx][ny] = x+100*y;
                            }
                            else if(par[x][y]!=nx+100*ny) {
                                cout << "Yes" << nl;
                                return;
                            }
                        }
                    }
                }
            }

        }
    }

    cout << "No" << nl;
}

signed main() {
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}