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
    ll n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    x1 = min(x1, n-x1+1);
    y1 =  min(y1, n-y1+1);
    x2 =  min(x2, n-x2+1);
    y2 =  min(y2, n-y2+1);

    ll ans1 = min(x1, y1);
    ll ans2 = min(x2, y2);

    cout << abs(ans1-ans2) << nl; 

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}