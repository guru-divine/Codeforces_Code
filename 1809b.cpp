//Author: guru_divine
#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mod 1000000007
using namespace std;

void solve() {
    ll n; cin >> n;
    // if(n==1) {
    //     cout << "0" << nl;
    //     return;
    // }
    ll num = sqrtl(n);
    if(num*num==n) num--;
    cout << num << nl;
    // if(num%2==0) {
    //     cout << num-1 << nl;
    // }
    // else {
    //     cout << num-1 << nl;
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