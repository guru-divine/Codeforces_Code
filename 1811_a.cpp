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
    int n;
    string s;
    char dig;
    cin >> n >> dig;
    cin >> s;

    for(int i=0; i<s.size(); ++i) {
        if(dig>s[i]) {
            s.insert(i, 1, dig);
            cout << s << nl;
            return;
        }
    }
    s += dig;
    cout << s << nl;
    return;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}