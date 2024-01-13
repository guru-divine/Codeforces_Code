//Author: DIVYA RAJ (aka guru_divine)
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define nl "\n"
#define pb push_back
#define popb pop_back
#define F first
#define S second
#define sz(arr) (int)arr.size()
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define mapi map<int, int>
#define un_mapi unordered_map<int, int>
#define mod 1000000007
#define fori(i,a,b) for(int i=a; i<=b; ++i)
#define ford(i,a,b) for(int i=a; i>=b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reversei(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()-1) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()-1) {cout << arr[i] << nl;}
using namespace std; 

void solve() {
    string s; cin >> s;
    int n=sz(s);
    int cntA = 0, cntB = 0;
    bool contB = 0;
    fori(i, 0, n-1) {
        if(s[i]=='A') cntA++;
        else cntB++;
        if(i && s[i]=='B' && s[i-1]=='B') contB=1;
    } 
    int ans = cntA;
    if(s[0]!='B' && s[n-1]!='B' && !contB) {
        int mini = 1e9;
        int i = 0, len = 0;
        while(i<n) {
            if(s[i]=='A') {
                while(i<n) {
                    if(s[i]=='B') break;
                    len++, i++;
                }
                mini = min(mini, len);
                len = 0;
            }
            else i++;
        }
        ans -= mini;
    }

    cout << ans << nl;
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}