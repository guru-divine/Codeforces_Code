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
    unordered_map<int, int> ump;
    int n; cin >> n;
    vector<vi> perm(n, vi(n-1));

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n-1; ++j) {
            cin >> perm[i][j];
            if(j==0) ump[perm[i][j]]++;
        }
    }
    int maxNum=0, maxIdx;
    for(auto it: ump) {
        if(it.second>maxNum) {
            maxNum = it.second;
            maxIdx = it.first;
        }
    }
    // cout << maxIdx << nl;

    vi ans;
    ans.pb(maxIdx);

    for(int i=0; i<n; ++i) {
        if(perm[i][0]!=maxIdx) {
            ans.insert(ans.end(), perm[i].begin(), perm[i].end());
            break;
        }
    }

    for(int i=0; i<n; ++i) {
        cout << ans[i] << " ";
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