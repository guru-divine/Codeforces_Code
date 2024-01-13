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
    int initSum, finalSum;
    cin >> initSum >> finalSum;

    int num = initSum - finalSum;
    cout << num << " ";

    int avg = finalSum/(n-1);
    int rem = finalSum%(n-1);

    for(int i=0; i<n-1; ++i) {
        int ans = avg;
        if(rem!=0) {
            ans++;
            rem--;
        }
        cout << ans << " ";
    }
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}