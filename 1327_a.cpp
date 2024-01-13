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

//If all odd +ve num are distinct,
// let k=3, n>=1+3+5=9=3*3
// Thus, n>=k*k

void solve() {
    ll n, k; cin >> n >> k;
    if(n>=k*k && n%2==k%2) {
        cout << "YES" << nl;
    }
    else cout << "NO" << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}