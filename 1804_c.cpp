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
    ll n, x, p;
    cin >> n >> x >> p;
    ll diff = (n-x)%n;

    for(ll i=1; i<=p; ++i) {
        ll num = (i*(i+1))/2;
        if(num%n==diff) {
            cout << "YES" << nl;
            return;
        }
        if(i>2*n) break;
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