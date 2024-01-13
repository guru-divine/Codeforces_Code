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
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;

    if((a-x)+(b-y)<=n) {
        cout << x*y << nl;
        return;
    }
    ll min1 = min(a-x, n);
    ll min2 = min(b-y, n);
    ll z1 = (a-min1)*(b-(n-min1));
    ll z2 = (b-min2)*(a-(n-min2));

    cout << min(z1, z2) << nl;
    // if(z1>z2) {
    //     cout << x*(b-n+(a-x)+1) << nl;
    // }
    // else {
    //     cout << (a-n+(b-y)+1)*y << nl;
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}