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

void dfs(int node, vi adj[], int height, int evenCnt, int oddCnt, vi &vis, vi &xori, vi &ans) {
    // cout << node+1 << " ";
    if(height%2==0) {
        if((evenCnt%2)^(xori[node])) {
            ans.pb(node+1);
            evenCnt++;
        }
    } else {
        if((oddCnt%2)^(xori[node])) {
            ans.pb(node+1);
            oddCnt++;
        }
    }
    for(auto child: adj[node]) {
        if(!vis[child]) {
            vis[child]=1;
            dfs(child, adj, height+1, evenCnt, oddCnt, vis, xori, ans);
        }
    }
}

void solve() {
    int n; cin >> n;
    vi adj[n];
    fori(i, 0, n-1) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi vis(n, 0);
    vi init(n), goal(n);
    fori(i, 0, n) {
        cin >> init[i];
    }
    fori(i, 0, n) cin >> goal[i];

    vi xori(n);
    fori(i, 0, n) xori[i] = init[i]^goal[i];

    int evenCnt=0, oddCnt=0;

    vi ans;
    vis[0]=1;
    dfs(0, adj, 0, evenCnt, oddCnt, vis, xori, ans);

    cout << ans.size() << nl;
    printN(ans);
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
