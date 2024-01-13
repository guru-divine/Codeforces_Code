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
    int n, x; cin >> n >> x;
    vi arr(n);
    vi rem(x, 0);
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
        rem[arr[i]%x]++;
    }
    int flag=0;
    for(int i=0; i<x; ++i) {
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