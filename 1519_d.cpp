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
    vi a(n), b(n);
    fori(i, 0, n) cin >> a[i];
    vi pref(n);
    fori(i, 0, n) {
        cin >> b[i];
        pref[i] = (a[i]*b[i]);
        if(i) pref[i] += pref[i-1];
    }
    int ans = pref[n-1];
    fori(mid, 0, n) {
        int curAns = 0;
        //for even length subarray
        for(int l=mid, r=mid+1; l>=0 && r<n; --l, ++r) {
            curAns += (a[l]*b[r] + a[r]*b[l]);
            ans = max(ans, ((l>0)?pref[l-1]:0)+curAns+pref[n-1]-pref[r]);
        }
        // cout << ans << " ";

        curAns = a[mid]*b[mid];
        //for odd length subarray 
        for(int l=mid-1, r=mid+1; l>=0 && r<n; --l, ++r) {
            curAns += (a[l]*b[r] + a[r]*b[l]);
            ans = max(ans, ((l>0)?pref[l-1]:0)+curAns+pref[n-1]-pref[r]);
        }
        // cout << ans << nl;
    }
    // cout << nl;

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