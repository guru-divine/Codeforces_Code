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
    string l, r; cin >> l >> r;
    int ans=0;
    if(l.size()==r.size()) {
        cout << ":)" << nl;
        ford(i, l.size()-1, 0) {
            if(l[i]=='0' && r[i]=='9') continue;
            if(r[i-1]-l[i-1]>0) {
                l[i]='9';
                r[i]='0';
            }
        }
        fori(i, 0, l.size()) {
            ans += abs(r[i]-l[i]);
        }
        cout << l << " " << r << nl;
    }
    else {
        cout << ":(" << nl;

        ford(i, l.size()-1, 0) {
            if(r[i-1]-l[i-1]>0) {
                l[i]='9';
                r[i]='0';
            }
        }
        fori(i, 0, l.size()) {
            ans += abs(r[i]-l[i]);
        }
        fori(i, l.size(), r.size()) {
            ans += abs(r[i]-'0');
        }
        cout << l << " " << r << nl;
    }
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