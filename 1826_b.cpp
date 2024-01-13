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

void solve() {
    int n; cin >> n;
    vi arr(n);
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
    }

    int ans = 0;
    for(int i=0; i<n/2; ++i) {
        if(i==n-i-1) continue;
        ans = __gcd(ans, abs(arr[i]-arr[n-i-1]));
    }
    if(ans==INT_MAX) ans = 0;
    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}