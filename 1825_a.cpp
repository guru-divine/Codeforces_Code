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
    unordered_map<int, int> ump;
    for(int i=0; i<s.size(); ++i) {
        ump[s[i]-'a']++;
    }
    if(ump.size()==1) {
        cout << "-1" << nl;
        return;
    }
    // int flag=0;
    // for(auto it: ump) {
    //     if(it.second & 1) flag=1;
    // }
    // if(flag) cout << s.size()-1 << nl;
    // else cout << s.size()-2 << nl;
    cout << s.size()-1 << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}