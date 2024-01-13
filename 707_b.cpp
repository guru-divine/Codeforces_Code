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
#define ford(i,a,b) for(int i=a; i<b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    un_mapi ump;
    vector<pii> adj[n+1];
    vi dis(n+1, INT_MAX);
    queue<pii> q;
    while(m--) {
        int u, v, l; cin >> u >> v >> l;
        adj[u].pb({v, l});
        adj[v].pb({u, l});
    }

    while(k--) {
        int x; cin >> x;
        dis[x]=0;
        q.push({x, 0});
    }

    while(!q.empty()) {
        int node = q.front().F;
        int dist = q.front().S;
        q.pop();
        for(auto child: adj[node]) {
            int chNode = child.F;
            int edgeWt = child.S;
            if(dis[chNode]>dist+edgeWt) dis[chNode]=dist+edgeWt;
        }
    }

    int mini=INT_MAX;
    fori(i, 1, n+1) {
        if(dis[i]) {
            mini = min(mini, dis[i]);
        }
    }
    if(mini==INT_MAX) cout << "-1" << nl;
    else cout << mini << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}