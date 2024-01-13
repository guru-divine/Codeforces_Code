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

int findParent(int node, vi &par) {
    while(node!=par[node]) {
        par[node] = par[par[node]];
        node = par[node];
    }
    return node;
}

void unionNode(int x, int y, vi &par, vi &size, int &reading) {
    if(x==y) return;
    int parX = findParent(x, par);
    int parY = findParent(y, par);

    if(parX!=parY) {
        if(size[parX]>=size[parY]) {
            par[parY] = parX;
            size[parX] += size[parY]; size[parY]=0;
            if(size[parX]==2) reading++;
        } else {
            par[parX] = parY;
            size[parY] += size[parX]; size[parX]=0;
            if(size[parY]==2) reading++;
        }
    }
}

void solve() {
    int n; cin >> n;
    vi par(n+1);
    vi size(n+1, 1);
    fori(i, 0, n+1) par[i]=i;

    int reading=0;
    fori(i, 0, n-1) {
        int x, y; cin >> x >> y;
        // int size1 = size[1];
        unionNode(x, y, par, size, reading);

        // if(size1==size[1]) reading++;    
    }
    // if(size[1]) reading++;

    cout << reading << nl;
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