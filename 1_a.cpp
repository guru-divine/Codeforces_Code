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
    ll n, m, a;
    ll ans;

    cin >> n >> m >> a;
    if(n%a==0 && m%a==0) {
        ans = (n/a)*(m/a);
    }
    else if(n%a!=0 && m%a==0) {
        ans = (n/a + 1)*(m/a);
    }
    else if(n%a==0 && m%a!=0) {
        ans = (n/a)*(m/a + 1);
    }
    else ans = (n/a + 1)*(m/a + 1);

    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}