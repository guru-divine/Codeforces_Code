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

int findLCM(vi &arr) {
    int lcm = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        int gcd_val = __gcd(lcm, arr[i]);
        lcm = (lcm*arr[i])/gcd_val;
    }
    return lcm;
}

void solve() {
    int n; cin >> n;
    vi arr(n+1);
    fori(i, 1, n+1) cin >> arr[i];

    vi lgcd(n+2, 0), rgcd(n+2, 0);

    fori(i, 1, n+1) {
        lgcd[i] = __gcd(arr[i], lgcd[i-1]);
    }
    ford(i, n, 1) {
        rgcd[i] = __gcd(arr[i], rgcd[i+1]);
    }

    // printS(lgcd); printS(rgcd);

    vi gcd;
    fori(i, 1, n+1) {
        int num = __gcd(lgcd[i-1], rgcd[i+1]); 
        gcd.pb(num);
    }
    int ans = findLCM(gcd);

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