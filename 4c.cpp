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

unordered_map<string, int> ump;

void solve() {
    int n; cin >> n;
    string s, newStr;
    for(int i=0; i<n; ++i) {
        cin >> s;
        if(ump[s]) {
            newStr = s+to_string(ump[s]);
            cout << newStr << nl;
            ump[s]++;
        }
        else {
            cout << "OK" << nl;
            ump[s]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}