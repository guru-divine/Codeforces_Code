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
    int n; cin >> n;
    vi adj[n+2];
    vi maxi(n+2, 0);
    vi cur(n+2, 0);
    vi mini(n+2, 0);
    vi curNeg(n+2, 0);

    maxi[1]=1;
    cur[1]=1;
    int cnt=2;

    fori(i, 0, n) {
        char c; cin >> c;
        if(c=='+') {
            int u, wt; cin >> u >> wt;
            adj[u].pb(cnt);
            adj[cnt].pb(u);

            cur[cnt] = cur[u]+wt;
            if(cur[cnt]<0) cur[cnt]=0;
            maxi[cnt] = max(maxi[u], cur[cnt]); 

            curNeg[cnt] = curNeg[u]+wt;
            if(curNeg[cnt]>0) curNeg[cnt]=0;
            mini[cnt] = min(mini[u], curNeg[cnt]);

            cnt++;
        }
        else {
            int u, v, k; cin >> u >> v >> k;
            if(k>=0) {
                if(maxi[v]>=k) cout << "YES" << nl;
                else cout << "NO" << nl;
            }
            else {
                if(mini[v]<=k) cout << "YES" << nl;
                else cout << "NO" << nl;
            }
            
        }
    }
    // cout << mini[2] << " " << mini[3] << " " << mini[5] << nl;
    // cout << maxi[3] << " " << cur[3] << nl;
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