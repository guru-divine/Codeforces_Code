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
    vi adj[n+1];
    vi vis(n+1, 0);

    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    queue<pii> q;
    q.push({1, 0});
    vis[1]=1;
    vi arr, brr;
    while(!q.empty()) {
        int node = q.front().F;
        int dist = q.front().S;
        if(dist%2==0) arr.pb(node);
        else brr.pb(node);
        q.pop();
        for(auto child: adj[node]) {
            if(!vis[child]) {
                vis[child]=1;
                q.push({child, dist+1});
            }
        }
    }

    if(arr.size()<=brr.size()) {
        cout << arr.size() << nl;
        printS(arr);
    } else {
        cout << brr.size() << nl;
        printS(brr);
    }
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