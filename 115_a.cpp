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

int dfs(int node, vi &adj, vi &depth, int &maxDepth) {
    // if(vis[node]) {
    //     maxDepth = max(maxDepth, depth[node]);
    //     return depth[node];
    // }
    // if(adj[node].size()==0) {
    //     vis[node]=1;
    //     depth[node] = 0;
    //     return 0;
    // }
    if(adj[node]==-1) {
        return depth[node]=1;
    }

    if(depth[node]!=-1) return depth[node];

    int ans = dfs(adj[node], adj, depth, maxDepth)+1;
    maxDepth = max(ans, maxDepth);

    return depth[node] = ans;
}

void solve() {
    int n; cin >> n;
    vi adj(n+1);

    for(int i=1; i<=n; ++i) {
        cin >> adj[i];
    }

    int maxDepth = 1;
    // vi vis(n, 0);
    vi depth(n+1, -1);
    for(int i=1; i<=n; ++i) {
        if(depth[i]==-1) {
            dfs(i, adj, depth, maxDepth);
        }
    }

    cout << maxDepth << nl;

    // for(int i=0; i<n; ++i) {

    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}