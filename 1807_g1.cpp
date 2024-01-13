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
    int cnt1=0;

    for(int i=0; i<n; ++i) {
        cin >> arr[i];
        if(arr[i]==1) cnt1++;
    }

    sort(arr.begin(), arr.end());

    int num = cnt1;
    for(int i=cnt1; i<n; ++i) {
        if(arr[i]>num) {
            cout << "NO" << nl;
            return;
        }
        num += arr[i];
        if(num>1000000) break;
    }

    cout << "YES" << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}