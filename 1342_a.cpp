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
    int x, y; cin >> x >> y;
    int a, b; cin >> a >> b;

    ll ans=0;
    if(2*a<b) {
        ans = 1LL*a*(x+y);
    }
    else {
        ans = 1LL*b*min(x, y) + 1LL*a*(max(x, y) - min(x, y));
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