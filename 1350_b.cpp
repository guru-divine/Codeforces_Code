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

int dp(int idx, bool flag, int prevIdx, int prevVal, vi &memo, vi &arr) {
    if(idx<1) return 0;
    if(memo[idx]!=-1) return memo[idx];

    int ans=0;
    if(!flag) {
        ans = max(ans, dp(idx-1, !flag, idx, arr[idx], memo, arr)+1);
    }
    else if(prevIdx%idx==0 && arr[idx]<prevVal) {
        ans = max(ans, dp(idx-1, flag, idx, arr[idx], memo, arr)+1);
    }

    ans = max(ans, dp(idx-1, flag, prevIdx, prevVal, memo, arr));

    return memo[idx] = ans;
}

void solve() {
    int n; cin >> n;
    vi arr(n+1);
    fori(i, 1, n+1) cin >> arr[i];

    vi len(n+1, 1);
    fori(i, 1, n+1) {
        for(int j=2*i; j<n+1; j+=i) {
            if(arr[j]>arr[i]) len[j] = max(len[j], len[i]+1);
        }
    }
    
    int maxLen = 1;
    fori(i, 1, n+1) {
        maxLen = max(maxLen, len[i]);
    }

    cout << maxLen << nl;
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