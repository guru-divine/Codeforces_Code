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
    vector<pii> adj[n];
    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].pb({v, w});
        adj[v].pb({u, -w});
    }

    vi dist(n, 1e18);
    vi vis(n, 0);
    queue<pii> q;
    fori(i, 0, n) {
        if(!vis[i]) {
            vis[i]=1;
            dist[i]=0;
            q.push({i, 0});
            while(!q.empty()) {
                int u = q.front().F;
                int wt = q.front().S;
                q.pop();
                for(auto it: adj[u]) {
                    int v = it.F;
                    int adjWt = it.S;
                    if(!vis[v]) {
                        vis[v]=1;
                        dist[v] = wt+adjWt;
                        q.push({v, dist[v]});
                    }
                    else {
                        if(dist[v]!=(wt+adjWt)) {
                            // cout << v  << " " << dist[v] << " " << wt+adjWt << nl;
                            cout << "NO" << nl;
                            return;
                        }
                    }
                }
            }
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