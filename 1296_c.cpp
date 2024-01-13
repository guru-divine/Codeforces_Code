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

bool cmp(pii &a, pii &b) {
    return ((a.S-a.F)<(b.S-b.F));
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<pii, int> mp;
    int x=0, y=0;
    mp[{0, 0}] = 1;

    vector<pii> ans;

    fori(i, 0, n) {
        if(s[i]=='U') y++;
        else if(s[i]=='D') y--;
        else if(s[i]=='L') x--;
        else x++;

        if(mp.find({x, y})!=mp.end()) {
            // cout << mp[{x, y}] << " " << i+1 << nl;
            // mp[{x, y}] = i+1;
            ans.pb({mp[{x, y}], i+1});
            mp[{x, y}] = i+2;
            // return;
        }
        else {
            mp[{x, y}] = i+2;
        }
    }

    sort(all(ans), cmp);
    if(sz(ans)) cout << ans[0].F << " " << ans[0].S << nl;
    else cout << "-1" << nl;

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