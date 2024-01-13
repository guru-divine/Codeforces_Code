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

void dfs(int u, vi adj[], vi &depth, vi &size, vi &vis) {
    for(auto v: adj[u]) {
        if(!vis[v]) {
            vis[v]=1;
            depth[v] = depth[u]+1;
            dfs(v, adj, depth, size, vis);
            size[u] += (1+size[v]);
        }
        
    }
}

void solve() {
    int n, k; cin >> n >> k;
    vi adj[n];
    fori(i, 0, n-1) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi depth(n, 0), size(n, 0), vis(n, 0);
    vis[0]=1;
    dfs(0, adj, depth, size, vis);

    vi hap(n);
    fori(i, 0, n) {
        hap[i] = depth[i] - size[i];
    }
    sortd(hap);

    int ans = 0;
    fori(i, 0, k) {
        ans += hap[i];
    }

    cout << ans << nl;
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