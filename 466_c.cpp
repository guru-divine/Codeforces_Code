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
    int n; cin >> n;
    int sum = 0;
    vi arr(n, 0);
    fori(i, 0, n) {
        cin >> arr[i];
        sum += arr[i];
    }

    if(sum%3!=0) {
        cout << "0" << nl;
        return;
    }
    vi pref(n, 0);
    fori(i, 0, n) {
        pref[i] = arr[i];
        if(i) pref[i] += pref[i-1];
    }

    vi leftIdx, rightIdx;
    fori(i, 0, n-1) {
        if(pref[i]==sum/3) leftIdx.pb(i);
        if(pref[i]==(2*sum)/3) rightIdx.pb(i);
    }
    // printS(leftIdx); printS(rightIdx);

    int ans=0;
    fori(i, 0, sz(leftIdx)) {
        ans += sz(rightIdx) - (upper_bound(all(rightIdx), leftIdx[i]) - rightIdx.begin());
    }

    cout << ans << nl;
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