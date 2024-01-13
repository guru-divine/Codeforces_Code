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
    string s; cin >> s;
    int m; cin >> m;
    string l, r; cin >> l >> r;

    int n = sz(s);

    int i=0, j=0;
    while(i<m) {

        vi vis(10, 0);
        int cnt=0;
        while(j<n) {
            if(s[j]>=l[i] && s[j]<=r[i] && !vis[s[j]-'0']) {
                vis[s[j]-'0']=1;
                cnt++;
            }
            j++;
            if(cnt==r[i]-l[i]+1) {
                i++;
                break;
            }

        }

        if(i!=m && j==n) {
            cout << "YES" << nl;
            return;
        }

    }

    cout << "NO" << nl;
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