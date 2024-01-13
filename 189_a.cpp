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

int dp(int len, vi &arr, vector<vi> &memo) {
    if(len==0) return 0;
    if(len<0) return INT_MIN;

    int ans = INT_MIN;
    fori(i, 0, 3) {
        if(memo[len][i]!=-1) return memo[len][i];

        memo[len][i] = dp(len-arr[i], arr, memo)+1;
        ans = max(ans, memo[len][i]);
    }

    return ans;
}

void solve() {
    vi arr(3);
    int n; cin >> n >> arr[0] >> arr[1] >> arr[2];
    sorti(arr);
    vector<vi> memo(n+2, vi(3, -1));

    cout << dp(n, arr, memo) << nl;
    // fori(i, 0, 3) {
    //     fori(j, 0, n+1) {
    //         cout << memo[j][i] << " ";
    //     }
    //     cout << nl;
    // }
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