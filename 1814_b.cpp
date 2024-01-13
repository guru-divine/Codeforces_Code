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
    ll a, b; cin >> a >> b;
    ll maxNum = max(a, b);
    ll minNum = min(a, b);

    // ll idx;
    // for(ll i=sqrtl(maxNum); i>0; --i) {
    //     if(maxNum%i==0) {
    //         idx = i;
    //         break;
    //     }
    // }

    ll ans=INT_MAX;
    for(ll i=1; i<=2*sqrtl(maxNum); ++i) {
        ll temp = (a+i-1)/i + (b+i-1)/i + (i-1);
        ans = min(ans, temp);
    }

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