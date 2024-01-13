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
    int n, m; cin >> n >> m;
    vi adj[n+1];
    un_mapi ump;
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        ump[u]++; ump[v]++;
    }

    int idx=-1;
    fori(i, 1, n+1) {
        if(!ump[i]) {
            idx = i;
            break;
        }
    }

    cout << n-1 << nl;
    fori(i, 1, n+1) {
        if(idx!=i) {
            cout << idx << " " << i << nl;
        }
    }
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}