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
    int n; cin >>n;

    vector<pii> vect(n);
    for(int i=0; i<n; ++i) {
        cin>> vect[i].first >> vect[i].second;
    }
    // for(int i=0; i<n; ++i) {
    //     cin>> vect[i].second;
    // }

    sort(vect.begin(), vect.end());

    for(int i=1; i<n; ++i) {
        if(vect[i-1].second>vect[i].second) {
            cout << "Happy Alex" << nl;
            return;
        }
    }
    cout << "Poor Alex" <<nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}