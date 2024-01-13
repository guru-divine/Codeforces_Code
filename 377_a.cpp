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
    int n, m, k; cin >> n >> m >> k;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vi> comp(n, vi(m));
    vector<vi> vis(n, vi(m, 0));

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    int safe = -k;
    fori(i, 0, n) {
        fori(j, 0, m) {
            cin >> grid[i][j];
            if(grid[i][j]=='.') safe++;
        }
    }

    queue<pii> q;
    int compNum=0, flag=0;
    fori(i, 0, n) {
        fori(j, 0, m) {
            int cnt=0;
            if(grid[i][j]=='.') {
                compNum++;
                q.push({i, j});
                vis[i][j]=1;
                while(!q.empty()) {
                    int x = q.front().F;
                    int y = q.front().S;
                    q.pop();

                    comp[x][y] = compNum;
                    cnt++;
                    if(cnt==safe) {
                        flag=1;
                        break;
                    }

                    fori(i, 0, 4) {
                        int xx = x+dx[i];
                        int yy = y+dy[i];
                        if(xx>=0 && xx<n && yy>=0 && yy<m && !vis[xx][yy] && grid[xx][yy]=='.') {
                            vis[xx][yy]=1;
                            q.push({xx, yy});
                        }
                    } 
                }
            }
            if(flag) break;
        }
        if(flag) break;
    }

    fori(i, 0, n) {
        fori(j, 0, m) {
            if(grid[i][j]=='.' && comp[i][j]!=compNum) {
                grid[i][j]='X';
            }
        }
    }


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