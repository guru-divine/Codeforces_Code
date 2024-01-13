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
    int k; cin >> k;
    vi month(12);
    for(int i=0; i<12; ++i) {
        cin >> month[i];
    }

    if(k==0) {
        cout << "0" << nl;
        return;
    }

    sort(month.begin(), month.end(), greater<int>());

    int sum=0;
    for(int i=0; i<12; ++i) {
        sum += month[i];
        if(sum >= k) {
            cout << i+1 << nl;
            return;
        }
    }

    cout << "-1" << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}