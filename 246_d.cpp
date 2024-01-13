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
    vi color(n);
    int ans = INT_MAX;
    int maxCol = 0;
    fori(i, 0, n) {
        cin >> color[i];
        ans = min(ans, color[i]);
        maxCol = max(maxCol, color[i]);
    }
    
    vector<set<int>> adj(maxCol+5);
    while(m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        if(color[u]!=color[v]) {
            adj[color[u]].insert(color[v]);
            adj[color[v]].insert(color[u]);
        }
    }

    int maxi = 0;
    fori(i, 0, sz(adj)) {
        if(adj[i].size()>maxi) {
            maxi = adj[i].size();
            ans = i;
        }
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