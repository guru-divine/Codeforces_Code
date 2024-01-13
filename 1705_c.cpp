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
    int n, c, q; cin >> n >> c >> q;
    string s; cin >> s;
    s.insert(s.begin(), '#');

    vi l(c+1), r(c+1), len(c+1, 0);
    len[0]=n;

    fori(i, 1, c+1) {
        cin >> l[i] >> r[i];
        len[i] = len[i-1] + (r[i]-l[i]+1);
    }
    // printS(len);
    while(q--) {
        int x; cin >> x;
        int i = c;
        while(i>0) {
            if(len[i-1]<x) {
                x = l[i] + (x-len[i-1]-1);
                // cout << x << " ";
            }
            i--;
        }
        // cout << nl;
        cout << s[x] << nl;
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