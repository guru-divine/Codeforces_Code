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
    // unordered_map<ll, ll> ump;

    ll n, m; cin >> n >> m;
    vll slope(n);

    for(ll i=0; i<n; ++i) {
        cin >> slope[i];
    }
    sort(slope.begin(), slope.end());
    slope.pb(LLONG_MAX);

    for(ll i=0; i<m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;

        if(a*c<0) {
            cout << "NO" << nl;
        }
        else {
            // ll temp = LLONG_MAX;

            ll temp = upper_bound(slope.begin(), slope.end(), b-2*sqrtl(a*c)) - slope.begin();
            ll temp2 = lower_bound(slope.begin(), slope.end(), b + 2*sqrtl(a*c)) - slope.begin();
            temp2--;
            if(temp>temp2) {
                cout << "NO" << nl;
            }
            else if(temp==temp2 && temp==n) {
                cout << "NO" << nl;
            }

            else {
                cout << "YES" << nl;
                cout << slope[temp] << nl;
            }
        }
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