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
#define ford(i,a,b) for(int i=a; i>=b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reversei(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    
    bool straight=1;
    int cntS=0, cntR=0;
    fori(i, 0, n) {
        if(s[i]==t[i]) cntS++;
        if(s[i]==t[n-i-1]) cntR++;
    }
    if(cntS==n) {
        cout << "0" << nl;
        return;
    }
    if(cntR==n) {
        cout << "2" << nl;
        return;
    }
    if(cntS<cntR) straight=0;

    int ans1 = 0, ans2=0;
    // if(straight) {
        ans1 += (n-cntS);
        if((n-cntS)%2==1) ans1 += (n-cntS-1);
        else ans1 += (n-cntS);
    // }
    // else {
        ans2 += (n-cntR);
        if((n-cntR)%2==1) ans2 += (n-cntR);
        else ans2 += (n-cntR-1);
    // }

    cout << min(ans1, ans2) << nl;

}

signed main() {
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}