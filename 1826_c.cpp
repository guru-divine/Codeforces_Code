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
    int n, m; cin >> n >> m;
    if(n==1) {
        cout << "YES" << nl;
        return;
    }
    // if(n%m==0) cout << "NO" << nl;
    // else cout << "YES" << nl;

    // if(m>=2 && )
    map<int, int> mp;
    int minNum = n;
    for(int i=2; i<=sqrt(n); ++i) {
        if(n%i==0) {
            minNum = min(minNum, i);
            break;
        }
        // if(n%i==0) {
        //     mp[i]++;
        //     if(i*i!=n) mp[n/i]++;
        // }
    }
    // mp[n]++;
    if(m >= minNum) cout << "NO" << nl;
    else cout << "YES" << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}