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
    vll arr(n);

    for(int i=0; i<n; ++i) {
        cin >> arr[i];
    }

    ll ans=0;
    int i=0;

    while(i<n) {
        ll maxPos = INT_MIN;
        ll minNeg = INT_MIN;

        if(arr[i]>0) {
            maxPos = max(maxPos, arr[i]);
            i++;
            while(i<n) {
                if(arr[i]<0) break;
                maxPos = max(maxPos, arr[i]);
                i++;
            }
            // cout << maxPos << " ";
            ans += maxPos;
        }
        else {
            maxPos = max(maxPos, arr[i]);
            i++;
            while(i<n) {
                if(arr[i]>0) break;
                maxPos = max(maxPos, arr[i]);
                i++;
            }
            // cout << maxPos << " ";
            ans += maxPos;
        }
    }
    // cout << nl;

    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}