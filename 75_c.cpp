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
    int a, b; cin >> a >> b;

    int num = __gcd(a, b);
    vi arr;
    for(int i=1; i<=sqrt(num); ++i) {
        if(num%i==0) {
            arr.pb(i);
            if(i*i!=num) arr.pb(num/i);
        }
    }
    sorti(arr);

    int q; cin >> q;
    while(q--) {
        int lo, hi; cin >> lo >> hi;
        auto it = lower_bound(all(arr), hi);
        if(it!=arr.end() && *it==hi) {
            cout << *it << nl;
        }
        else {
            it--;
            if(*it>=lo) cout << *it << nl;
            else cout << "-1" << nl;
        }
    }
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