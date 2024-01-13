//Author: DIVYA RAJ
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define nl "\n"
#define pb push_back
#define popb pop_back
#define F first
#define S second
#define sz(arr) arr.size()
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define mapi map<int, int>
#define un_mapi unordered_map<int, int>
#define mod 1000000007
#define fori(i,a,b) for(int i=a; i<b; ++i)
#define ford(i,a,b) for(int i=a; i<b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

void solve() {
    string s = "Yes";
    string inp; cin >> inp;
    string ans=inp;
    if(inp[0]=='Y') {
        fori(i, 0, sz(inp)) {
            ans[i] = s[i%3];
        }
        if(ans==inp) cout << "YES" << nl;
        else cout << "NO" << nl;
    }
    else if(inp[0]=='e') {
        fori(i, 0, sz(inp)) {
            ans[i] = s[(i%3 + 1)%3];
        }
        if(ans==inp) cout << "YES" << nl;
        else cout << "NO" << nl;
    }
    else if(inp[0]=='s') {
        fori(i, 0, sz(inp)) {
            ans[i] = s[(i%3 + 2)%3];
        }
        if(ans==inp) cout << "YES" << nl;
        else cout << "NO" << nl;
    }
    else {
        cout << "NO" << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}