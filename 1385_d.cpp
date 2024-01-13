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

int dp(int l, int r, string &s, char c) {
    if(l==r) return (s[l]!=c);

    int mid = (l+r)/2;
    int cntLeft=0, cntRight=0;
    fori(i, l, mid+1) {
        if(s[i]!=c) cntLeft++;
    }
    fori(i, mid+1, r+1) {
        if(s[i]!=c) cntRight++;
    }
    int ans = 1e9;
    c++;
    ans = min(ans, dp(mid+1, r, s, c)+cntLeft);
    ans = min(ans, dp(l, mid, s, c)+cntRight);

    return ans;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    cout << dp(0, n-1, s, 'a') << nl;
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