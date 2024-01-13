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
    int l, r;
    cin >> l >> r;
    int maxDiff = -1;
    int num;
    for(int i=l; i<=r; ++i) {
        string str = to_string(i);
        sort(str.begin(), str.end());

        int diff = str[str.size()-1] - str[0];

        if(diff>maxDiff) {
            num = i;
            maxDiff = diff;
        }

        if(maxDiff==9) {
            cout << num << nl;
            return;
        }
    }
    cout << num << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}