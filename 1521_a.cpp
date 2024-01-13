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
    int a, b; cin >>a >> b;
    if(b==1) cout << "NO" << nl;
    else {
        cout << "YES" << nl;
        if(b==2) {
            cout << a << " " << 1LL*a*(b+1) << " " << 1LL*a*b*2 << nl;
            return;
        }
        cout << a << " " << 1LL*a*(b-1) << " " << 1LL*a*b << nl;
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