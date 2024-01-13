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
    if(k > (n+1)/2) {
        k -= (n+1)/2;
        ll ans = 2*k;
        cout << ans << nl;
        return;
    }
    else {
        ll ans = 2*k - 1;
        cout << ans << nl;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}