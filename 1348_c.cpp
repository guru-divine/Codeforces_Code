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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    sorti(s);

    int initSame = 0;
    ford(i, k-1, 0) {
        if(s[i]!=s[k-1]) break;
        initSame++;
    }
    if(initSame==k) {
        int latSame = 0;
        fori(i, k, n) {
            if(s[i]!=s[k]) break;
            latSame++;
        }

        string ans;
        ans.pb(s[k-1]);
        if(latSame==n-k) {
            int cnt = (n-k+k-1)/k;
            while(cnt--) ans.pb(s[k]);
        }
        else {
            fori(i, k, n) ans.pb(s[i]);
        }
        cout << ans << nl;
    }
    else cout << s[k-1] << nl;
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