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
    map<int, int> mp;

    int n; cin >> n;
    for(int i=0; i<n; ++i) {
        int x; cin >> x;
        mp[x]++;
    }

    int prevIdx, prevVal;
    int j=0;

    int ans = 0;
    for(auto it: mp) {
        if(!j) {
            prevIdx = it.first;
            prevVal = it.second;
        }

        if(j) {
            if(it.first > prevIdx+1) {
                ans += prevVal;
            }
            else {
                if(prevVal>it.second) {
                    ans += (prevVal-it.second);
                }
            }
        }
        j++;
        prevIdx = it.first;
        prevVal = it.second;
    }

    ans += prevVal;

    cout << ans << nl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}