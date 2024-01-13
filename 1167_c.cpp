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
#define reverse(arr) reverse(arr.begin(), arr.end())
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

void unionNode(int x, int y, vi &par, vi &size) {
    if(x==y) return;
    int parX = findParent(x, par);
    int parY = findParent(y, par);

    if(parX!=parY) {
        if(size[parX]>=size[parY]) {
            par[parY] = parX;
            size[parX] += size[parY]; size[parY]=0;
        } else {
            par[parX] = parY;
            size[parY] += size[parX]; size[parX]=0;
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vi par(n+1);
    vi size(n+1, 1);
    fori(i, 0, n+1) par[i]=i;

    while(m--) {
        int num; cin >> num;
        int flag=0, x;
        while(num--) {
            if(!flag) {
                cin >> x;
                flag=1;
            }
            else {
                int y; cin >> y;
                unionNode(x, y, par, size);
            }
        }
    }

    // printS(par); printS(size);
    fori(i, 1, n+1) {
        cout << size[findParent(i, par)] << " ";
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}