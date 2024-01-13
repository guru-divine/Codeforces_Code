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
    vector<pii> arr;
    if(n>8) {
        fori(i, 9, n) {
            arr.pb({i, n});
        }
        fori(i, 3, 8) {
            arr.pb({i, 8});
        }

        int dupN = n;
        while(dupN!=1) {
            arr.pb({n, 8});
            dupN = (dupN+7)/8;
        }
        dupN = 8;
        while(dupN!=1) {
            arr.pb({8, 2});
            dupN = (dupN+1)/2;
        }
    }
    else {
        fori(i, 3, n) {
            arr.pb({i, n});
        }
        int dupN = n;
        while(dupN!=1) {
            arr.pb({n, 2});
            dupN = (dupN+1)/2;
        }
    }

    cout << arr.size() << nl;
    fori(i, 0, sz(arr)) {
        cout << arr[i].F << " " << arr[i].S << nl;
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