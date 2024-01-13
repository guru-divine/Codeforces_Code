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
    int n, k, g; cin >> n >> k >> g;
    int totSilv = k*g;
    if((n-1)*(g/2 - (1-g%2))>=totSilv) {
        cout << totSilv << nl;
        return;
    }

    int num = 0;
    num = (n-1)*(g/2 - (1-g%2));

    int left = totSilv-num;
    // cout << left << nl;
    int modi = left%g;
    // cout << modi << nl;
    // int ans = 0;
    // if(modi*2>=g) {
    //     ans = ((totSilv-num)/g + 1)*g;
    // }
    // else ans = (totSilv-num)*g;

    int ans = (left/g + (modi*2>=g))*g;

    cout << totSilv-ans << nl;
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