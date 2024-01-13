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
    ll n, deleteCost, insertCost;
    cin >> n >> deleteCost >> insertCost;

    vi arr(n);

    int num = 0, flag=0;
    ll temp = deleteCost*(n) + insertCost;
    ll ans=0;

    for(int i=0; i<n; ++i) {
        cin >> arr[i];

        if(flag==0) {

        if(arr[i]<=num) {
            ans += deleteCost;
            // continue;
        }
        else if(arr[i]==num+1) {
            num = arr[i];
            // continue;
        }
        else {
            int diff = arr[i]-num-1;
            if(deleteCost*(n-i)<=insertCost*diff) {
                ans += deleteCost*(n-i);
                flag=1;
            }
            else {
                ans += insertCost*diff;
                num = arr[i];
            }
        }
        // cout << ans << " ";
        }
    }
    // cout << ans << " ";
    ans = min(ans, temp);

    cout << ans << nl;
    // if(flag) cout << "***" << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}