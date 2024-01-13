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
    ump['a'] = ump['e'] = ump['i'] = ump['o'] = ump['u'] = ump['y'] = 1;
    string s; cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string ans;

    for(int i=0; i<s.size(); ++i) {
        if(!ump[s[i]]) {
            ans += '.';
            ans += s[i];
        }
    }

    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}