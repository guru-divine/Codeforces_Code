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
    int n; cin >> n;
    string s; cin >> s;
    vi lowerAlph(26, 0);
    int cnt=0;
    for(int i=0; i<s.size(); ++i) {
        if(i%2==0) {
            lowerAlph[s[i]-'a']++;
        }
        else {
            if(lowerAlph[s[i]-'A']==0) cnt++;
            else lowerAlph[s[i]-'A']--;
        }
    }
    cout << cnt << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}