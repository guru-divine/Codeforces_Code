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

void dfs(int node, int flag, int cnt, int &ans, int &k, vi &vis, vi &cat, vi adj[]) {
    if(flag) {
        if(cat[node]) cnt++;
        else {
            cnt=0; flag=0;
        }
    } else {
        if(cat[node]) {
            cnt++; flag=1;
        }
    }
    if(cnt>k) return;
    if(node!=1 && adj[node].size()==1 && cnt<=k) ans++;
    vis[node]=1;
    for(auto child: adj[node]) {
        if(!vis[child]) {
            vis[child]=1;

            dfs(child, flag, cnt, ans, k, vis, cat, adj);
        }

    }

}

void solve() {
    int n, k; cin >> n >> k;
    vi adj[n+1];
    vi cat(n+1, 0);
    fori(i, 1, n+1) cin >> cat[i];

    fori(i, 0, n-1) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int ans=0, cnt=0;
    vi vis(n+1, 0);
    dfs(1, 0, cnt, ans, k, vis, cat, adj);

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