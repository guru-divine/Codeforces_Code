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
    string s; cin >> s;
    int n = s.size();

    vi cntOne(n, 0), cntZero(n, 0);
    fori(i, 0, n) {
        if(s[i]=='0') cntZero[i] = 1;
        else cntOne[i] = 1;
    }

    fori(i, 1, n) {
        cntZero[i] += cntZero[i-1];
        cntOne[i] += cntOne[i-1];
    }

    // printS(cntZero);
    // printS(cntOne);

    int ans = INT_MAX;
    //Case 1: 111111000000000
    fori(i, 0, n) {
        int curAns = ((!i) ? 0 :cntZero[i-1]) + (cntOne[n-1]-(cntOne[i]));
        ans = min(ans, curAns);
    }

    //Case 2: 0000001111111111
    fori(i, 0, n) {
        int curAns = ((!i) ? 0 :cntOne[i-1]) + (cntZero[n-1]-(cntZero[i]));
        ans = min(ans, curAns);
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