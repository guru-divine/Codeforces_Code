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


//we have to always swap a subsequence of even size
//So, we take adjacent twos and find max subarray
void solve() {
    int n; cin >> n;
    vi arr(n);
    int sumEven = 0;
    fori(i, 0, n) {
        cin >> arr[i];
        if(i%2==0) sumEven += arr[i];
    }
    vi diff1, diff2;
    for(int i=1; i<n; i+=2) {
        diff1.pb(arr[i]-arr[i-1]);
    }
    for(int i=2; i<n; i+=2) {
        diff2.pb(arr[i-1]-arr[i]);
    }

    // printS(diff1);
    // printS(diff2);

    int maxi = 0;
    vi maxSub(n, 0);
    for(int i=0; i<diff1.size(); ++i) {
        maxSub[i] = max(0LL, ((i>0)?maxSub[i-1]:0)+diff1[i]);
        maxi = max(maxi, maxSub[i]);
    }
    fori(i, 0, n) maxSub[i]=0;

    fori(i, 0, diff2.size()) {
        maxSub[i] = max(0LL, ((i>0)?maxSub[i-1]:0)+diff2[i]);
        maxi = max(maxi, maxSub[i]);
    }

    int ans = sumEven + maxi;
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