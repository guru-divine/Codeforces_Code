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
    vi n(3);
    cin >> n[0] >> n[1] >> n[2];

    string s;

    if(n[1]!=0) {
        string s1, s2;
        fori(i, 0, (n[1]+1)/2) s += "10";
        fori(i, 0, n[2]) s1.pb('1');
        fori(i, 0, n[0]) s2.pb('0');

        s = s1+s+s2;
        if(n[1]%2==0) s.pb('1');
        
    }
    else {
        if(n[0]) {
            fori(i, 0, n[0]+1) s.pb('0');
        }
        else {
            fori(i, 0, n[2]+1) s.pb('1');
        }
    }

    cout << s << nl;
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