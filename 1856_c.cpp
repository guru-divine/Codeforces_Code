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

void func(int idx, vi &arr, int &ans, int k) {
    if(idx-1>=0 && k>=arr[idx]+1-arr[idx-1]) {

        arr[idx-1] = arr[idx]+1;
        ans = max(ans, arr[idx-1]);
        k -= (arr[idx]+1-arr[idx-1]);


        func(idx-1, arr, ans, k);
    }
}

void fuc(int idx, vi arr, int &ans, int k) {

}

void solve() {
    int n, k; cin >> n >> k;
    vi arr(n), brr(n);
    int maxi = INT_MIN;
    fori(i, 0, n) {
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
        brr[i] = arr[i];
    }

    if(n==1) {
        cout << arr[0] << nl;
        return;
    }

    sortd(brr);
    if(brr[0]-brr[1]>=k) {
        cout << brr[0] << nl;
        return;
    }

    vi maxIdx;
    fori(i, 0, n) {
        if(arr[i]==maxi) maxIdx.pb(i);
    }
    // printS(maxIdx);

    int ans = maxi;
    fori(i, 0, sz(maxIdx)) {
        func(maxIdx[i], arr, ans, k);
    }

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