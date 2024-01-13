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
    ll n, k;
    cin >> n >> k;

    if(n%2==1 && k%2==0) {
        cout << "NO" << nl;
        return;
    }

    if(n%2==k%2) {
        if(n>=k) {
            cout << "YES" << nl;
            for(int i=0; i<k-1; ++i) {
                cout << "1 ";
            }
            cout << n - (k-1) << nl;
            return;
        }
        else {
            cout << "NO" << nl;
            return;
        }
    }
    if(n%2==0 && k%2==1) {
        if(n>=2*k) {
            cout << "YES" << nl;
            for(int i=0; i<k-1; ++i) {
                cout << "2 ";
            }
            cout << n - 2*(k-1) << nl;
            return;
        }
        else {
            cout << "NO" << nl;
            return;
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