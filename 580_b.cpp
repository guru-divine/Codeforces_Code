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
    int n, d; cin >> n >> d;
    vector<pii> arr(n);
    fori(i, 0, n) {
        cin >> arr[i].F >> arr[i].S;
    }

    sorti(arr);
    vi brr(n), pref(n);
    fori(i, 0, n) {
        brr[i] = arr[i].F;

        pref[i] = arr[i].S;
        if(i) pref[i] += pref[i-1];
    }
    // printS(pref);

    int ans = 0;
    for(int i=0; i<n; ++i) {
        int hi = lower_bound(all(brr), brr[i]+d) - brr.begin();
        hi--;
        int temp = pref[hi] - ((i==0)?0:pref[i-1]);
        ans = max(ans, temp);
    }

    cout << ans << nl;
    
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