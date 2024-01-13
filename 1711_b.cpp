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
    vector<pii> unHappy(n+1);
    vi uH(n+1);
    fori(i, 1, n+1) {
        int x; cin >> x;
        uH[i] = x;
        unHappy[i] = {x, i};
    }
    unHappy[0]={-1,0};
    sorti(unHappy);

    vi adj[n+1];
    fori(i, 0, m) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(m%2==0) {
        cout << "0" << nl;
        return;
    }

    int mini = INT_MAX;
    int flag=0;
    fori(i, 1, n+1) {
        int unHap = unHappy[i].F;
        int idx = unHappy[i].S;

        if(adj[idx].size()%2==1) {
            mini = min(mini, unHap);
            cout << mini << nl;
            return;
        }
        else {
            for(auto child: adj[idx]) {
                if(adj[child].size()%2==0) {
                    mini = min(mini, unHap + uH[child]);
                }
            }
        }
    }
    cout << mini << nl;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}