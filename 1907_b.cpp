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
    set<pair<int, char>> upper, lower;
    string s; cin >> s;
    fori(i, 0, sz(s)-1) {
        if(s[i]=='b') {
            auto it = lower.end();
            if(it==lower.begin()) continue;
            it--;
            lower.erase(it);
        }
        else if(s[i]=='B') {
            auto it = upper.end();
            if(it==upper.begin()) continue;
            it--;
            upper.erase(it);
        }
        else if(s[i]<='Z') {
            upper.emplace(make_pair(i, s[i]));
        }
        else {
            lower.emplace(make_pair(i, s[i]));
        }
    }
    vector<pair<int, char>> ans;
    for(auto it: lower) ans.pb(it);
    for(auto it: upper) ans.pb(it);
    sorti(ans);
    string str;
    for(auto it: ans) {
        str += it.S;
    }
    cout << str << nl;
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