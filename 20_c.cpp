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
    vector<pii> adj[n+1];
    while(m--) {
        int u, v, dist; cin >> u >> v >> dist;
        // u--; v--;
        adj[u].pb({dist, v});
        adj[v].pb({dist, u});
    }

    vi dist(n+1, 1e18);
    vi par(n+1, -1);
    set<pii> st;
    dist[1]=0;
    st.insert({0, 1});

    while(!st.empty()) {
        auto it = *st.begin();
        int dis = it.F;
        int node = it.S;
        st.erase(it);

        for(auto itr: adj[node]) {
            int edgeWt = itr.F;
            int adjNode = itr.S;

            if(dis + edgeWt < dist[adjNode]) {
                if(dist[adjNode]!=1e18) st.erase({dist[adjNode], adjNode});

                dist[adjNode] = edgeWt + dis;
                st.insert({dist[adjNode], adjNode});
                par[adjNode] = node;
            }
        }
    }

    int node = n;
    if(par[node]==-1) {
        cout << "-1" << nl;
        return;
    }

    vi path;
    while(node!=-1) {
        path.pb(node);
        node = par[node];
    }
    reversei(path);
    printS(path);
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