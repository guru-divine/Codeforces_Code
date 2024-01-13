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
    int n, time; cin >> n >> time;
    vi arr(n), brr(n);

    int idx=-2, maxHap=0;
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
        arr[i] += i;
    }
    for(int i=0; i<n; ++i) {
        cin >> brr[i];
        if(arr[i]<=time && brr[i]>maxHap) {
            idx = i;
            maxHap = brr[i];
        }
    }
    cout << idx+1 << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}