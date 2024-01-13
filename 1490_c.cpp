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

bool isPair(ll a, ll num) {
    return (a*a*a <= num);
}

void solve() {
    ll n; cin >> n;

    if(n==1) {
        cout << "NO" << nl;
        return;
    }

    ll cuberoot = cbrtl(n);
    if(cuberoot*cuberoot*cuberoot==n) cuberoot--;

    for(ll i=1; i<=cuberoot; ++i) {
        ll ans = cbrtl(n-(i*i*i));
        if(ans*ans*ans==(n-(i*i*i))) {
            cout << "YES" << nl;
            return;
        }

        // ll lo = 1;
        // ll hi = cbrtl(n);
        // while(lo<=hi) {
        //     ll mid = (lo+hi)/2;
        //     if(isPair(mid, ans)) {
        //         if(mid*mid*mid==ans) {
        //             cout << "YES" << nl;
        //             cout << i << " " << mid << nl;
        //             return;
        //         }
        //         lo = mid+1;
        //     }
        //     else hi = mid-1;
        // }
    }
    cout << "NO" << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}