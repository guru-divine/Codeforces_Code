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

bool check(int &mid, vi &arr) {
    auto it = upper_bound(all(arr), arr[0]+2*mid);
    if(it==arr.end()) return true;

    it = upper_bound(all(arr), (*it)+2*mid);
    if(it==arr.end()) return true;

    it = upper_bound(all(arr), (*it)+2*mid);
    if(it==arr.end()) return true;

    return false;
}

void solve() {
    int n; cin >> n;
    vi arr(n);
    fori(i, 0, n) cin >> arr[i];

    sorti(arr);

    int lo = 0, hi = arr[n-1]-arr[0];
    int ans = 0;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        
        if(check(mid, arr)) {
            ans = mid; hi=mid-1;
        }
        else lo=mid+1;
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