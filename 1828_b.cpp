//Author: DIVYA RAJ
#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define pb push_back
#define popb pop_back
#define F first
#define S second
#define sz(arr) arr.size()
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mapi map<int, int>
#define un_mapi unordered_map<int, int>
#define mod 1000000007
#define fori(i,a,b) for(int i=a; i<b; ++i)
#define forll(i,a,b) for(ll i=a; i<b; ++i)
#define ford(i,a,b) for(int i=a; i<b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

void solve() {
    // set<int> st;
    vll arr;
    int n; cin >> n;
    // vll arr(n);
    ll minDiff=INT_MAX;
    forll(i, 1, n+1) {
        int x; cin >> x;
        ll diff = abs(x-i);
        arr.pb(diff);
        // st.insert(diff);
        // if(diff) minDiff = min(minDiff, diff);
    }
    // if(minDiff==INT_MAX) cout << "0" << nl;
    // else cout << minDiff << nl;

    // for(auto it: st) {
    //     int num=it;
    //     for(auto j=lower_bound(st.begin(), st.end(), num); j!=st.end(); ++)
    // }

    ll ans=0;
    forll(i, 0, arr.size()) {
        ans = __gcd(ans, arr[i]);
    }
    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}