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

int bfs(int n, vi adj[]) {
    vi dist(n+1, 1e9);
    dist[1]=0;
    set<pii> st;
    st.insert({0, 1});
    while(!st.empty()) {
        auto it = *st.begin();
        int u = it.S;
        int distU = it.F;
        st.erase(it);
        for(auto v: adj[u]) {
            if(distU+1<dist[v]) {
                if(dist[v]!=1e9) st.erase({dist[v], v});
                dist[v] = distU+1;
                st.insert({dist[v], v});
            }
        }
    }
    return dist[n];
}

void solve() {
    int n, m; cin >> n >> m;
    vi adj[n+1];
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int minTime = bfs(n, adj);

    vi newAdj[n+1];
    fori(i, 1, n+1) {
        vi vis(n+1, 0);
        fori(j, 0, sz(adj[i])) {
            vis[adj[i][j]]=1;
        }
        fori(j, 1, n+1) {
            if(i==j) continue;
            if(!vis[j]) {
                newAdj[i].pb(j);
            }
        }
    }

    int time = bfs(n ,newAdj);
    minTime = max(minTime, bfs(n, newAdj));
    if(minTime==1e9) cout << "-1" << nl;
    else cout << minTime << nl;
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