//Author: DIVYA RAJ
#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define pb push_back
#define popb pop_back
#define F first
#define S second
#define sz(arr) arr.size()
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define map map<int, int>
#define un_map unordered_map<int, int>
#define mod 1000000007
#define fori(i,a,b) for(int i=a; i<b; ++i)
#define forll(i,a,b) for(ll i=a; i<b; ++i)
#define ford(i,a,b) for(int i=a; i<b; --i)
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

void solve() {
    int n; cin >> n;
    // vi arr; vector<string> str(n);

    ll min1=INT_MAX, min2=INT_MAX, minAll=INT_MAX;

    fori(i, 0, n) {
        ll x; cin >> x;
        string str; cin >> str;

        if(str=="01") min2 = min(x, min2);
        else if(str=="10") min1 = min(min1, x);
        else if(str=="11") minAll = min(minAll, x);
        // cin >> arr[i] >> str[i];
    }

    int minNum = min(min1+min2, minAll);
    if(minNum>=INT_MAX) cout << "-1" << nl;
    else cout << minNum << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}