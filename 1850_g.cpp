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
    map<int, int> vert;
    map<int, int> horiz;
    map<int, int> left;
    map<int, int> right;
    fori(i, 0, n) {
        int x, y; cin >> x >> y;
        vert[y]++;
        horiz[x]++;
        left[x-y]++;
        right[y+x]++;
    }

    int ans=0;
    for(auto it: vert) {
        ans += (it.S*(it.S-1));
    }
    for(auto it: horiz) {
        ans += (it.S*(it.S-1));
    }
    for(auto it: left) {
        ans += (it.S*(it.S-1));
    }
    for(auto it: right) {
        ans += (it.S*(it.S-1));
    }

    cout << ans << nl;
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