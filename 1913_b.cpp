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
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std; 

void solve() {
    string s; cin >> s;
    int n = sz(s);
    vi prefZero(n, 0), prefOne(n, 0);
    fori(i, 0, n-1) {
        if(s[i]-'0') prefOne[i] = 1;
        else prefZero[i] = 1;
        if(i) {
            prefOne[i] += prefOne[i-1];
            prefZero[i] += prefZero[i-1];
        }
    }
    // printS(prefZero); printS(prefOne);
    int ans = n;
    int lo = 0, hi = n-1;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        
        if(prefZero[n-1]>=prefOne[n-1-mid] && prefOne[n-1]>=prefZero[n-1-mid]) {
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    cout << ans << nl;
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