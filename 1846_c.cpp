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

bool cmp(pii a, pii b) {
    if(a.F==b.F) return (a.S<b.S);
    return (a.F>b.F);
}

void solve() {
    int n, m, h; cin >> n >> m >> h;
    vector<pii> mst;
    vi mat[n];

    fori(i, 0, n) {
        fori(j, 0, m) {
            int x; cin >> x;
            mat[i].pb(x);
        }
    }

    fori(i, 0, n) sorti(mat[i]);

    pii rudolf={100, 100};
    fori(i, 0, n) {
        int penalty = 0;
        int numProb = 0;
        int pref = 0, j=0;
        while(j<m && pref<=h) {
            pref+=mat[i][j];
            if(pref<=h) {
                penalty += pref;
                numProb++;
            }
            j++;
        }
        if(!i) rudolf = {numProb, penalty};
        mst.pb({numProb, penalty});
    }

    sort(all(mst), cmp);

    // for(auto it: mst) {
    //     cout << it.F << " " << it.S << nl;
    // }
    // cout << ".................." << nl;
    fori(i, 0, sz(mst)) {
        if(mst[i].F==rudolf.F && mst[i].S==rudolf.S) {
            cout << i+1 << nl;
            return;
        }
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