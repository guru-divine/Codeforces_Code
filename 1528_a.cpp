//Author: DIVYA RAJ (aka guru_divine)
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define nl "\n"
#define pb push_back
#define popb pop_back
#define F first
#define S second
#define sz(arr) (int)arr.size()
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define mapi map<int, int>
#define un_mapi unordered_map<int, int>
#define mod 1000000007
#define fori(i,a,b) for(int i=a; i<=b; ++i)
#define ford(i,a,b) for(int i=a; i>=b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reversei(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std; 

int dp(int idx, int choice, int prev, vi adj[], vector<vi> &range, vector<vi> &memo) {
    if(memo[idx][choice]!=-1) return memo[idx][choice];
    int ans = 0;
    for(auto v: adj[idx]) {
        if(v==prev) continue;
        ans += max(dp(v, 0, idx, adj, range, memo) + abs(range[v][0]-range[idx][choice]),
                    dp(v, 1, idx, adj, range, memo) + abs(range[v][1]-range[idx][choice]));
    }
    return memo[idx][choice] = ans;
}

void solve() {
    int n; cin >> n;
    vector<vi> range(n, vi(2));
    vi adj[n];
    fori(i, 0, n-1) cin >> range[i][0] >> range[i][1];
    fori(i, 0, n-2) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    vector<vi> memo(n+2, vi(2, -1));
    int ans = max(dp(0, 1, -1, adj, range, memo), dp(0, 0, -1, adj, range, memo));
    cout << ans << nl;
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}