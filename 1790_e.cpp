//Author: guru_divine
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mod 1000000007
using namespace std;

void dfs(int node, int cnt, unordered_map<int, int> &painted, vi &vis, vi adj[], int &minDist) {
    if(cnt>=minDist) return;

    for(auto child: adj[node]) {
        if(!vis[child]) {
            vis[child]=1;

            if(painted[child]==1) {
                minDist = min(minDist, cnt);
                return;
            }
            else {
                dfs(child, cnt+1, painted, vis, adj, minDist);
            }
        }
        
    }
}

void solve() {
    int n, initial; cin >> n >> initial;
    vi color(n-1);
    for(int i=0; i<n-1; ++i) {
        cin >> color[i];
    }

    vi adj[n+1];
    for(int i=0; i<n-1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    // vi painted(n+1,0);
    unordered_map<int, int> painted;
    painted[initial]=1;

    int minDist = INT_MAX;
    for(int i=0; i<n-1; ++i) {
        painted[color[i]]=1;
        for(auto node: painted) {
            vi vis(n+1, 0);
            // cout << node.first << " ";
            dfs(node.first, 1, painted, vis, adj, minDist);
        }

        cout << minDist << " ";
    }
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}