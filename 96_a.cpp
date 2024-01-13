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
    string s; cin >> s;
    int n = s.size();
    int cnt=1;
    for(int i=0; i<n; ++i) {
        // int cnt=1;
        if(s[i]==s[i+1]) {
            cnt++;
            if(cnt==7) {
                cout << "YES" << nl;
                return;
            }
        }
        else cnt=1;
    }
    cout << "NO" << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}