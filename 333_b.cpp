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
    int n, m; cin >> n >> m;
    vi rowBanned(n, 0), colBanned(n, 0);
    while(m--) {
        int x, y; cin >> x >> y;
        x--, y--;
        rowBanned[x]=1, colBanned[y]=1;
    }
    mapi mp;
    int cnt = 0;
    fori(i, 1, n-1) {
        if(!rowBanned[i]) {
            mp[min(i, n-i-1)]=1;
            cnt++;
        }
    }
    fori(i, 1, n-1) {
        if(!colBanned[i] && (mp.find(i)==mp.end() || mp.find(n-1-i)==mp.end())) {
            cnt++;
        }
    }

    cout << cnt << nl;
}

signed main() {
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}