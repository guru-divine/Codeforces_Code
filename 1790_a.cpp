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
    string ans = "314159265358979323846264338327950288419";
    string s; cin >> s;

    int cnt=0;
    for(int i=0; i<s.size(); ++i) {
        if(s[i]==ans[i]) cnt++;
        else break;
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