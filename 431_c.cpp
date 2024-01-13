#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
long long mod = 1e9 + 7;

lli n, k, d;

vector<vector<lli>> dp(110, vector<lli>(110, -1));

lli rec(lli i, lli j) {
    if(i > n) return 0;
    else if(i == n && j > 0) return 1;
    else if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    for (int x = 1; x <= k; x++) {
        ans += rec(i + x, j + (x >= d));
        ans %= mod;
    }

    return dp[i][j] = ans;
}

int main() {
    cin >> n >> k >> d;
    cout << rec(0, 0) << endl;
}
