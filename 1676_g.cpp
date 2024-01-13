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

int subTree(int idx, int &cnt, vi adj[], vi &color, vi &dp) {
    if(adj[idx].empty()) return dp[idx] = color[idx];
    if(dp[idx]!=INT_MIN) return dp[idx];

    int sum = color[idx];
    for(auto child: adj[idx]) {
        sum += subTree(child, cnt, adj, color, dp);
    }
    if(sum==0) cnt++;
    return dp[idx] = sum;
}

void solve() {
    int n; cin >> n;
    vi adj[n+1];
    fori(i, 2, n+1) {
        int x; cin >> x;
        adj[x].pb(i);
    }

    vi color(n+1, 0);
    string s; cin >> s;
    fori(i, 0, sz(s)) {
        if(s[i]=='W') color[i+1]=1;
        else color[i+1]=-1;
    }
    // printS(color);

    int cnt=0;
    vi dp(n+1, INT_MIN);

    subTree(1, cnt, adj, color, dp);
    // printS(dp);

    cout << cnt << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}