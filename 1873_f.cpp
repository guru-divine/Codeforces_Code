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
    int n, k; cin >> n >> k;
    vi arr(n+1), height(n+1);
    vi pref(n+1, 0);
    int mini = 1e9;
    fori(i, 1, n+1) {
        cin >> arr[i];
        mini = min(mini, arr[i]);
        pref[i] = arr[i]+pref[i-1];
    }
    fori(i, 1, n+1) cin >> height[i];

    if(mini>k) {
        cout << "0" << nl;
        return;
    }
 
    vector<pii> pairi;
    int i = 1;
    while(i<=n) {
        int l = i;
        i++;
        while(i<=n && height[i-1]%height[i]==0) {
            i++;
        }
        int r = i-1;
        if(r-l>=1) pairi.pb({l, r});
    }
 
    int maxi = 1;
    fori(i, 0, sz(pairi)) {
        pii cur = pairi[i];
        int lo = cur.F, hi = cur.S;
        // cout << lo << "," << hi << nl; 
        fori(j, lo, hi+1) {
            int len = (upper_bound(all(pref), pref[j-1]+k) - pref.begin()) - j;
            // cout << j << " " << len << nl;
            maxi = max(maxi, min(len, hi-j+1));
        }
    }
 
    cout << maxi << nl;
}
 
signed main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t; cin >> t;
    while(t--) solve();
    return 0;
}