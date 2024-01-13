//Author: guru_divine
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mod 1000000007
using namespace std;

int dfs(int idx, int sum, int n, vi &arr, vi &dp, int &maxPath) {
    if(idx>n) {
        // maxPath = max(maxPath, sum+arr[idx]);
        return 0;
    }

    if(dp[idx]!=-1) return dp[idx];

    int ans = arr[idx] + dfs(idx+arr[idx], sum+arr[idx], n, arr, dp, maxPath);
    maxPath = max(ans, maxPath);

    return dp[idx] = ans;
}

void solve() {
    int n; cin >> n;
    vi arr(n+1);
    for(int i=1; i<=n; ++i) {
        cin >> arr[i];
    }

    int maxPath=-1;
    vi dp(n+1, -1);

    for(int i=1; i<=n; ++i) {
        dfs(i, 0, n, arr, dp, maxPath);
        // cout << maxPath << " ";
    }

    cout << maxPath << nl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}