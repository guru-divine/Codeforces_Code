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
    int n, k; cin >> n >> k;
    vi indegree(n, 0);
    vi adj[n];
    fori(i, 0, n-1) {
        int u, v; cin >> u >> v;
        u--; v--;
        indegree[u]++;
        indegree[v]++;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    int ans = n;
    queue<pii> q;
    fori(i, 0, n) {
        if(indegree[i]==1) q.push({i, 1});
        else if(indegree[i]==0) ans--;
    }

    while(!q.empty()) {
        int u = q.front().F;
        int h = q.front().S;
        if(h>k) break;
        q.pop();
        ans--;
        for(auto v: adj[u]) {
            indegree[v]--;
            if(indegree[v]==1) q.push({v, h+1});
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

    int t; cin >> t;
    while(t--) solve();
    return 0;
}