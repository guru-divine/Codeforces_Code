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
    ll n, k; cin >> n >> k;

    if(k%(n-1)==0) {
        ll ans = (k/(n-1))*n - 1;
        cout << ans << nl;
        // cout <<"*";
        return;
    }
    else {
        ll ans = (k/(n-1))*n + (k%(n-1));
        cout << ans << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}