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
    ll n, m; cin >> n >> m;
    ll num = __gcd(n, m);
    n /= num;
    m /= num;

    if(n==m) {
        cout << "YES" << nl;
        return;
    }
    if(m>n) {
        cout << "NO" << nl;
        return;
    }
    int cnt1=0, cnt2=0;
    while(n!=1) {
        if(n%3!=0) {
            cout << "NO" << nl;
            return;
        } 
        cnt1++;
        n/=3;
    }
    while(m!=1) {
        if(m%2!=0) {
            cout << "NO" << nl;
            return;
        }
        cnt2++;
        m/=2;
    }

    if(cnt1>=cnt2) cout << "YES" << nl;
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