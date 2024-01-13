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
    ll sum=0;
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr.begin(), arr.end(), greater<int>());

    ll ansSum = 0;
    for(int i=0; i<n; ++i) {
        ansSum += arr[i];
        if(ansSum > sum/2) {
            cout << i+1 << nl;
            return;
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