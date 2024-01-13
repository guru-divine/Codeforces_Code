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

int maxPillar(int idx, int &k, int &prevVal, vi &memo, vi &arr) {
    if(idx<0) return 0;
    int ans = 0;
    ans = max(ans, maxPillar(idx-1, k, prevVal, memo, arr));
    if(abs(arr[idx]-prevVal)>=k) {
        prevVal = arr[idx];
        ans = max(ans, maxPillar(idx-1, k, prevVal, memo, arr)+1);
    }

    return memo[idx] = ans;
}

void solve() {
    int n, k; cin >> n >> k;
    vi arr(n);
    fori(i, 0, n) cin >> arr[i];
    vi memo(n, -1);

    int prevVal = 1e18;
    maxPillar(n-1, k, prevVal, memo, arr);
    int ans = 0;
    fori(i, 0, n) {
        ans = max(ans, memo[i]);
    }

    cout << ans << nl;
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