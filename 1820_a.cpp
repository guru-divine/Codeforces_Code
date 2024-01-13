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

    if(n==1 && s[0]=='^') {
        cout << "1" << nl;
        return;
    }

    int cnt=0;
    int ans = 0;
    for(int i=0; i<n; ++i) {
        cnt=0;
        if(s[i]=='_') {
            i++;
            cnt++;
            while(i<n) {
                if(s[i]!='_') break;
                cnt++;
                i++;
            }
            if(cnt!=0) ans += cnt-1;
            cnt=0;
        }
        // if(cnt!=0) ans += cnt-1;
    }
    // if(cnt!=0) ans += cnt-1;
    if(s[0]=='_') ans++;
    if(s[n-1]=='_') ans++;

    cout << ans << nl; 
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}