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

int findPar(int x, vi &par) {
    if(x==par[x]) return x;
    return par[x] = findPar(par[x], par);
}

void merge(int x, int y, vi &par, vi &size) {
    int parx = findPar(x, par);
    int pary = findPar(y, par);
    if(parx==pary) return;

    if(size[parx]>=size[pary]) {
        par[pary] = parx;
        size[parx] += size[pary];
        size[pary] = 0;
    } else {
        par[parx] = pary;
        size[pary] += size[parx];
        size[parx] = 0;
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vi adj[n];
    vi par(n), size(n, 1);
    fori(i, 0, n) par[i]=i;
    map<pii, int> mp;

    while(m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        // if(u>v) swap(u, v);
        // if(mp.find({u, v})==mp.end()) {
            // mp[{u, v}]++;
            adj[u].pb(v);
            adj[v].pb(u);
            merge(u, v, par, size);
        // }
    }

    fori(i, 0, n) {
        int pari = findPar(par[i], par);
        int sizei = size[pari];
        if(sizei>=3) {
            if(adj[i].size()!=(sizei-1)) {
                cout << "NO" << nl;
                return;
            }
        }
    }
    cout << "YES" << nl;

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