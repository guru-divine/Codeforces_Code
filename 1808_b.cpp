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

bool cmp(int a, int b) {
    return a>b;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> game(m);
    
    int x;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin >> x;
            game[j].pb(x);
        }
    }
    for(int i=0; i<m; ++i) {
        sort(game[i].begin(), game[i].end(), cmp);
    }

    ll cnt=0;
    for(int i=0; i<m; ++i) {
        int multfactor = n-1;
        for(int j=0; j<n; ++j) {
            cnt += 1LL*(multfactor)*game[i][j];
            multfactor-=2;
        }
    }
    cout << cnt << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}