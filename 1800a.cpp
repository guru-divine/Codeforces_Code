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
    int j=0;
    string test = "meow-";
    for(int i=0; i<s.size(); ++i) {
        // if(i && (s[i]==s[i-1] || s[i]+'A'-'a'==s[i-1] || s[i]+'a'-'A'==s[i-1])) continue;
        if(i) {
            if(s[i]==s[i-1]) continue;
            else if(s[i]>s[i-1] && s[i]+'A'-'a'==s[i-1]) continue;
            else if(s[i]<s[i-1] && s[i]+'a'-'A'==s[i-1]) continue;
        }

        if(s[i]==test[j] || s[i]==test[j]+'A'-'a') j++;
        else {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}