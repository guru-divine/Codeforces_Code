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

void dfs(int u, vi adj[], vi &par, vi &vis, int &mini) {

}

void solve() {
    int n; cin >> n;
    vi adj[n];
    vi cost(n);
    fori(i, 0, n) cin >> cost[i];
    int m; cin >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
    }
    vi vis(n, 0);
    vi par(n);
    fori(i, 0, n) par[i] = i;

    int mini = 1e18;
    fori(i, 0, n) {
        if(!vis[i]) {
            dfs(i, adj, par, vis, mini);
        }
    }

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