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

void kmp(string &t, int &len) {
    int n = t.size();
    vi lps(n+1);

    lps[0]=-1;
    int i=0, j=-1;
    while(i<n) {
        while(j!=-1 && t[i]!=t[j]) j = lps[j];
        i++; j++;
        lps[i] = j;
    }

    if(lps[n]!=0) {
        fori(i, 0, n) {
            if(lps[i]==lps[n]) {
                len = lps[n];
                return;
            }
        }
        len = lps[lps[n]];
        return;
    } 

    // cout << t << nl;
    // printS(lps);
}

void solve() {
    string s; cin >> s;
    int len = 0;

    kmp(s, len);

    string str = "Just a legend";
    if(len) str = s.substr(0, len);

    cout << str << nl;
}

signed main() {
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}