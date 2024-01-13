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
    int n, k;
    cin >> n >> k;

    int j=0;
    // vi adj(n+1, -1);
    for(int i=0; i<n-1; ++i) {
        int x; cin >> x;
        if(!i) {
            ump[i+x]=1;
            j = i+x;
        }
        else {
            if(i==j) {
                ump[i+x]=1;
                j = i+x;
            }
        }
    }
    if(ump[k-1]==1) cout << "YES" << nl;
    else cout << "NO" << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}