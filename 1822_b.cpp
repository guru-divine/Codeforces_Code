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
    ll n; cin >> n;
    vll arr(n), pos, neg;
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
        if(arr[i]==0) {
            pos.pb(arr[i]);
            neg.pb(arr[i]);
        }
        else if(arr[i]>0) pos.pb(arr[i]);
        else neg.pb(arr[i]);
    }
    if(n==2) {
        cout << arr[0]*arr[1] << nl;
        return;
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    reverse(pos.begin(), pos.end());

    ll maxPos=0, maxNeg=0;
    if(pos.size()>=2) maxPos = pos[0]*pos[1];
    if(neg.size()>=2) maxNeg = neg[0]*neg[1];

    ll maxnum = max(maxPos, maxNeg);
    cout << maxnum << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}