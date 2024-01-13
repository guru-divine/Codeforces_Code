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
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
    }

    int idx=0;
    ll sum=0, ans = INT_MAX;
    for(int i=0; i<k; ++i) {
        sum += arr[i];
    }
    if(sum<ans) {
        idx = 0;
        ans = sum;
    }

    for(int i=k; i<n; ++i) {
        sum += (arr[i] - arr[i-k]);
        if(sum<ans) {
            idx = i-k+1;
            ans = sum;
        }
    }

    cout << idx+1 << nl; //1-indexed
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}