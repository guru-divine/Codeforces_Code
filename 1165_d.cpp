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
    vi arr(n);
    mapi mp;

    int ans = 1;
    bool notPossible = 0;

    fori(i, 0, n) {
        cin >> arr[i];
        mp[arr[i]]++;

        if(!i) ans = arr[i];
        else {
            if(ans>LLONG_MAX/arr[i]) {
                notPossible = 1;
            }
            ans = (ans*arr[i])/__gcd(arr[i], ans);
        }
    }
    if(notPossible) {
        cout << "-1" << nl;
        return;
    }

    sorti(arr);

    if(ans==arr[n-1]) ans *= arr[0];

    for(int i=2; i<=sqrt(ans); ++i) {
        if(ans%i==0) {
            if(mp.find(i)==mp.end() || mp.find(ans/i)==mp.end()) {
                cout << "-1" << nl;
                return;
            }
        }
    }

    cout << ans << nl;

    // fori(i, 0, n) {
    //     int num = arr[i];
    //     for(int j=2; j<=sqrt(num); ++j) {
    //         if(num%j==0) {
    //             if(mp.find(j)==mp.end() || mp.find(num/j)==mp.end()) {
    //                 // cout << j << " " << num << nl;
    //                 cout << "-1" << nl;
    //                 return;
    //             }
    //         }
    //     }
    // }
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