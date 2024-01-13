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
    int n; cin >> n;
    vll sum(3, 0);

    int x;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<3; ++j) {
            cin >> x;
            sum[j] += x;
        }
    }

    for(int i=0; i<3; ++i) {
        if(sum[i]!=0) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}