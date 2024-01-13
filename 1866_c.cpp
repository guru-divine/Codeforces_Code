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
#define mod 998244353
#define fori(i,a,b) for(int i=a; i<b; ++i)
#define ford(i,a,b) for(int i=a; i>=b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reversei(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

void dfs(int u, vector<pii> adj[], int &cnt, int &ans) {
    for(auto it: adj[u]) {
        int v = it.F;
        int wt = it.S;
        if(wt==0) ans = (ans+cnt)%mod;
        else cnt++;
        dfs(v, adj, cnt, ans);
    }
}

void solve() {
    int n; cin >> n;
    vector<pii> adj[n+1];
    fori(i, 1, n+1) {
        int m; cin >>m ;
        while(m--) {
            int u, wt; cin >> u >> wt;
            adj[i].pb({u, wt});
        }
    }

    int cnt = 0, ans = 0;
    dfs(1, adj, cnt, ans);

    ans = ans%mod;
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