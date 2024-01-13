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
    string sample = "hello";
    string s; cin >> s;

    int j=0;
    for(int i=0; i<s.size(); ++i) {
        if(s[i]==sample[j]) j++;

        if(j==5) {
            cout << "YES" << nl;
            return;
        }
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