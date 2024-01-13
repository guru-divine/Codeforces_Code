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
#define ford(i,a,b) for(int i=a; i<b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

void solve() {
    int n; cin >> n;
    vi arr(n);
    int totSum=0, tempSum=0, maxSum=0;
    fori(i, 0, n) {
        cin >> arr[i];
        totSum += arr[i];
    }

    fori(i, 1, n) {
        tempSum += arr[i];
        tempSum = max(tempSum, 1LL*0);
        maxSum = max(maxSum, tempSum);
    }
    tempSum=0;
    fori(i, 0, n-1) {
        tempSum += arr[i];
        tempSum = max(tempSum, 1LL*0);
        maxSum = max(maxSum, tempSum);
    }

    if(maxSum>=totSum) cout << "NO" << nl;
    else cout << "YES" << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}