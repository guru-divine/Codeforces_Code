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

bool check(int x, int y, int &n, int &m) {
    if(x>=0 && x<n && y>=0 && y<m) return 1;
    return 0;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vi> vis(n, vi(m, 0));
    fori(i, 0, n) {
        fori(j, 0, m) {
            cin >> grid[i][j];
        }
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    queue<pii> q;
    fori(i, 0, n) {
        if(grid[i][0]=='.') q.push({i, 0});
        if(grid[i][m-1]=='.') q.push({i, m-1});
    }
    fori(i, 0, m) {
        if(grid[0][i]=='.') q.push({0, i});
        if(grid[n-1][i]=='.') q.push({n-1, i});
    }
    while(!q.empty()) {
        int x = q.front().F;
        int y = q.front().S;
        q.pop();
        // grid[x][y]='*';
        vis[x][y]=1;
        fori(i, 0, 4) {
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(check(xx, yy, n, m) && !vis[xx][yy] && grid[xx][yy]=='.') {
                vis[xx][yy]=1;
                q.push({xx, yy});
            }
        }
    }

    vector<pair<int, pii>> sizeLake;
    int startx, starty;
    fori(i, 0, n) {
        fori(j, 0, m) {
            if(!vis[i][j] && grid[i][j]=='.') {
                q.push({i, j});
                vis[i][j]=1;
                startx=i; starty=j;
                int size = 0;
                while(!q.empty()) {
                    int x = q.front().F;
                    int y = q.front().S;
                    q.pop();
                    size++;
                    fori(l, 0, 4) {
                        int xx = x+dx[l];
                        int yy = y+dy[l];
                        if(check(xx, yy, n, m) && !vis[xx][yy] && grid[xx][yy]=='.') {
                            vis[xx][yy]=1;
                            q.push({xx, yy});
                        }
                    }
                }
                sizeLake.pb({size, {startx, starty}});
            }
        }
    }

    sortd(sizeLake);
    int ans=0;
    fori(i, k, sz(sizeLake)) {
        ans += sizeLake[i].F;
    }

    queue<pii> fill;
    fori(i, k, sz(sizeLake)) {
        int posx = sizeLake[i].S.F;
        int posy = sizeLake[i].S.S;
        fill.push({posx, posy});
        while(!fill.empty()) {
            int x = fill.front().F;
            int y = fill.front().S;
            grid[x][y]='*';
            fill.pop();
            fori(i, 0, 4) {
                int xx = x+dx[i];
                int yy = y+dy[i];
                if(check(xx, yy, n, m) && grid[xx][yy]=='.') {
                    fill.push({xx, yy});
                }
            }
        }
    }

    cout << ans << nl;
    fori(i, 0, n) {
        fori(j, 0, m) {
            cout << grid[i][j];
        }
        cout << nl;
    }
    cout << nl;
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