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
    queue<pii> good, bad;

    fori(i, 0, n) {
        fori(j, 0, m) {
            cin >> mat[i][j];
            if(mat[i][j]=='G') good.push({i, j});
            else if(mat[i][j]=='B') bad.push({i, j});
        }
    }

    if(good.empty()) {
        cout << "YES" << nl;
        return;
    }

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    while(!bad.empty()) {
        int x = bad.front().F;
        int y = bad.front().S;
        bad.pop();
        fori(i, 0, 4) {
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(xx>=0 && xx<n && yy>=0 && yy<m) {
                if(mat[xx][yy]=='G') {
                    cout << "NO" << nl;
                    return;
                }
                else if(mat[xx][yy]=='.') mat[xx][yy]='#';
            }
        }
    }
    if(mat[n-1][m-1]=='#') {
        cout << "NO" << nl;
        return;
    }

    queue<pii> q;
    vector<vi> vis(n, vi(m, 0));
    q.push({n-1, m-1});
    vis[n-1][m-1]=1;
    while(!q.empty()) {
        int x = q.front().F;
        int y = q.front().S;
        vis[x][y]=1;
        q.pop();
        fori(i, 0, 4) {
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(xx>=0 && xx<n && yy>=0 && yy<m) {
                if(!vis[xx][yy] && (mat[xx][yy]=='.' || mat[xx][yy]=='G')) {
                    vis[xx][yy]=1;
                    q.push({xx, yy});
                }
            }
        }
    }

    while(!good.empty()) {
        int x = good.front().F;
        int y = good.front().S;
        good.pop();
        if(!vis[x][y]) {
            cout << "NO" << nl;
            return;
        }
    }

    cout << "YES" << nl;

}

signed main() {
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}