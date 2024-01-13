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
    int m; cin >> m;
    vector<vi> vect(m);
    vector<vi> ans(m);

    for(int i=0; i<m; ++i) {
        int n; cin >> n;
        for(int j=0; j<n; ++j) {
            int x; cin >> x;
            vect[i].pb(x);
        }
    }

    for(int i=m-1; i>=0; --i) {
        for(int j=0; j<vect[i].size(); ++j) {
            if(ump[vect[i][j]]==1) continue;
            else {
                ans[i].pb(vect[i][j]);
                ump[vect[i][j]]=1;
            }
        }
        if(ans[i].size()==0) {
            cout << "-1" << nl;
            return;
        }
    }

    for(int i=0; i<m; ++i) {
        cout << ans[i][0] << " ";
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