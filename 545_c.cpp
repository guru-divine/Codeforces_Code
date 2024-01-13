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

int dp(int idx, int dirn, int mini, vector<pii> &arr, vector<vi> &memo) {
    // dirn: 0->left, 1->leave, 2->right

    if(idx<0) return 0;
    if(memo[idx][dirn]!=-1) return memo[idx][dirn];

    int ans = 0;

    if((arr[idx].F+arr[idx].S)<mini) {
        ans = max(ans, dp(idx-1, 2, arr[idx].F, arr, memo)+1);
    }
    if(arr[idx].F<mini) {
        ans = max(ans, dp(idx-1, 0, arr[idx].F-arr[idx].S, arr, memo)+1);
        ans = max(ans, dp(idx-1, 1, arr[idx].F, arr, memo));
    }

    return memo[idx][dirn]=ans;
}

void solve() {
    int n; cin >> n;
    vector<pii> arr(n);

    fori(i, 0, n) {
        cin >> arr[i].F >> arr[i].S;
    }
    sorti(arr);

    vector<vi> memo(n+5, vi(3, -1));

    int mini = INT_MAX;
    dp(n-1, 2, mini, arr, memo);

    // fori(i, 0, 3) {
    //     fori(j, 0, n+5) {
    //         cout << memo[j][i] << " ";
    //     }
    //     cout << nl;
    // }

    int ans = max(memo[n-1][0], max(memo[n-1][1], memo[n-1][2]));
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