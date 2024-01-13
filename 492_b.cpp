//Author: DIVYA RAJ
#include <bits/stdc++.h>
#define ll long long
#define ld long double
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
    int n, l; cin >> n >> l;
    vi arr(n);

    fori(i, 0, n) cin >> arr[i];

    sorti(arr);

    int maxDiff = 0;
    maxDiff = max(maxDiff, arr[0]*2);
    maxDiff = max(maxDiff, (l-arr[n-1])*2);
    fori(i, 1, sz(arr)) {
        maxDiff = max(maxDiff, arr[i]-arr[i-1]);
    }
    
    printf("%0.10lf", maxDiff/2.0);
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