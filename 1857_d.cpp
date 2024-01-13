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
    vi arr(n), brr(n);
    fori(i, 0, n) {
        cin >> arr[i];
    }
    fori(i, 0, n) {
        cin >> brr[i];
    }
    vector<pii> diff(n);
    fori(i, 0, n) {
        diff[i].F = arr[i]-brr[i];
        diff[i].S = i+1;
    }

    sorti(diff);
    int maxi = diff[n-1].F;
    int i=n-1;
    vi ans;
    while(i>=0) {
        if(diff[i].F==maxi) {
            ans.pb(diff[i].S);
            i--;
        }
        else break;
    }

    cout << ans.size() << nl;
    sorti(ans);
    printS(ans);

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