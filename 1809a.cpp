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
    unordered_map<char, int> ump;
    int cnt=0;
    string s; cin >> s;
    for(int i=0; i<4; ++i) {
        ump[s[i]]++;
    }
    if(ump.size()==1) cout << -1 << nl;
    else if(ump.size()==2) {
        if(ump.begin()->second==1 || ump.begin()->second==3) {
            cout << "6" << nl;
        }
        else {
            cout << "4" << nl;
        }
    }
    else cout << "4" << nl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}