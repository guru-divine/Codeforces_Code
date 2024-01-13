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
    ll a, b;
    cin >> a >> b;
    ll diff = abs(a-b);
    if(diff==0) {
        cout << "0 0" << nl;
        return;
    }
    ll ans = a%diff;
    cout << diff << " " << min(ans, diff - ans) << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}