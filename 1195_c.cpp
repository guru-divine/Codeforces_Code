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

int dp(int idx, int flag, vector<vi> &memo, vector<vi> &row) {
    if(idx<0) return 0;
    if(memo[flag][idx]!=-1) return memo[flag][idx];

    int ans = 0;
    ans = max(ans, dp(idx-1, !flag, memo, row)+row[flag][idx]);
    ans = max(ans, dp(idx-1, flag, memo, row));

    return memo[flag][idx]=ans;
}

void solve() {
    int n; cin >> n;
    vector<vi> row(2, vi(n));

    fori(i, 0, 2) {
        fori(j, 0, n) {
            cin >> row[i][j];
        }
    }

    vector<vi> memo(2, vi(n+5, -1));

    int ans1 = dp(n-1, 0, memo, row);
    int ans2 = dp(n-1, 1, memo, row);
    int ans = max(ans1, ans2);

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