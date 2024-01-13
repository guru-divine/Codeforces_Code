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
    vll prefSum(n+1, 0);

    for(int i=0; i<n; ++i) {
        cin >> arr[i];
        prefSum[i+1] = prefSum[i]+arr[i];
    }
    sort(arr.begin(), arr.end());
    vll prefSumSort(n+1, 0);

    for(int i=0; i<n; ++i) {
        prefSumSort[i+1] = prefSumSort[i]+arr[i];
    }

    int m; cin >> m;
    while(m--) {
        int type, l, r;
        cin >> type  >> l >> r;

        if(type==1) {
            ll ans = prefSum[r]-prefSum[l-1];
            cout << ans << nl;
        }
        else {
            ll ans = prefSumSort[r]-prefSumSort[l-1];
            cout << ans << nl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}