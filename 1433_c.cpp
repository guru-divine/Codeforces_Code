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
    int maxNum = 0;
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
        maxNum = max(maxNum, arr[i]);
    }

    for(int i=0; i<n; ++i) {
        if(arr[i]==maxNum) {
            if(i && arr[i]>arr[i-1]) {
                cout << i+1 << nl;
                return;
            }
            else if(i<n-1 && arr[i]>arr[i+1]) {
                cout << i+1 << nl;
                return;
            }
        }
    }

    cout << "-1" << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}