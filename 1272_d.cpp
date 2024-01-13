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

// int dp(int idx, int prev, bool flag, vi &arr, vector<vi> &memo) {
//     if(idx<0) return 0;
//     if()
// }

void solve() {
    int n; cin >> n;
    vi arr(n);
    fori(i, 0, n) cin >> arr[i];

    vi left(n, 1), right(n, 1);

    fori(i, 1, n) {
        if(arr[i]>arr[i-1]) left[i] = left[i-1]+1;
    }
    ford(i, n-2, 0) {
        if(arr[i]<arr[i+1]) right[i] = right[i+1]+1;
    }

    // printS(left);
    // printS(right);

    int maxSeq=0;
    fori(i, 1, n-1) {
        if(arr[i-1]<arr[i+1]) maxSeq = max(maxSeq, left[i-1]+right[i+1]);
    }
    fori(i, 0, n) {
        maxSeq = max(maxSeq, left[i]);
    }

    cout << maxSeq << nl;
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