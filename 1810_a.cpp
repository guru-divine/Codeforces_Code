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
    vi arr(n);
    int flag=0;
    for(int i=0; i<n; ++i) {
        cin >> arr[i];

        if(arr[i]<=(i+1)) {
            // cout << "YES" << nl;
            flag=1;
        }
    }

    if(flag==1) cout << "YES" << nl;
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