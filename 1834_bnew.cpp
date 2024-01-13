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

void dfs(int idx, string &l, string &r) {
    int n = l.size();
    int pos = -1;
    fori(i, idx+1, n) {
        if(r[i]>l[i]) {
            pos = i;
            break;
        }
    }
    if(pos!=-1) {
        l[idx]='9';
        r[idx]='0';
    }
}

void solve() {
    string l, r; cin >> l >> r;
    reversei(l); reversei(r);
    while(l.size()!=r.size()) {
        l.pb('0');
    }
    int n = l.size();

    int ans=0;
    
    fori(i, 0, n) {
        if(l[i]=='9' && r[i]=='0') continue;
        dfs(i, l, r);
    }

    fori(i, 0, n) ans += abs(r[i]-l[i]);
    cout << ans << nl;
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