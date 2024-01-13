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

void dfs(int node, vi adj[], vi &child, vi &vis) {
    int flag=0;
    for(auto v: adj[node]) {
        if(!vis[v]) {
            flag=1;
            vis[v]=1;
            dfs(v, adj, child, vis);
            child[node] += child[v];
        }
    }
    if(flag==0) child[node]=1;
}



void solve() {
    int n; cin >> n;
    vi adj[n+1];
    fori(i, 0, n-1) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi child(n+1, 0);
    vi vis(n+1, 0);
    vis[1]=1;
    // queue<int> q;
    // q.push(1);

    // while(!q.empty()) {
    //     int u = q.front();
    //     q.pop();
    //     for(auto v: adj[u]) {
    //         if(!vis[v]) {
    //             vis[v]=1;
    //             child[u]++;
    //         }
    //     }
    // }
    dfs(1, adj, child, vis);
    // printS(child);
    int q; cin >> q;
    while(q--) {
        int x, y; cin >> x >> y;
        int ans = child[x]*child[y];
        cout << ans << nl;
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