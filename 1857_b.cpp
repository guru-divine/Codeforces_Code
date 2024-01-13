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
    reversei(s);
    s.pb('0');

    int idx = -1;
    int i=0;
    while(i<sz(s)-1) {
        if(s[i]>='5') {
            if(s[i]=='9') {
                i++;
                while(i<sz(s)-1) {
                    if(s[i]!='9') break;
                    i++;
                }
                s[i]+=1;
                idx = i-1;
            }
            else {
                s[i+1]+=1;
                idx = i;
                i++;
            }
        }
        else i++;
    }

    fori(i, 0, idx+1) {
        s[i] = '0';
    }

    if(s.back()=='0') s.pop_back();
    reversei(s);

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