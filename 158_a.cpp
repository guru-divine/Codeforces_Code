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
    int n, k;
    cin >> n >> k;

    vi arr(n);
    int cnt=0;

    for(int i=0; i<n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int val = arr[n-k];
    if(val>0) {
        cout << arr.end() - lower_bound(arr.begin(), arr.end(), val) << nl;
        // cout << lower_bound(arr.begin(), arr.end(), val) - arr.begin() << nl;
    }
    else {
        cout << arr.end() - upper_bound(arr.begin(), arr.end(), 0) << nl;
    }
    // cout << cnt << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}