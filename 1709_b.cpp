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
    int n, m; cin >> n >> m;
    vi arr(n);
    fori(i, 0, n-1) cin >> arr[i];
    vi pref(n, 0), suf(n, 0);
    fori(i, 1, n-1) {
        if(arr[i]<arr[i-1]) pref[i] = (arr[i-1]-arr[i]);
        pref[i] += pref[i-1];
    }
    ford(i, n-2, 0) {
        if(arr[i]<arr[i+1]) suf[i] = (arr[i+1]-arr[i]);
        suf[i] += suf[i+1];
    }

    // printS(pref);
    // printS(suf);

    while(m--) {
        int l, r; cin >> l >> r;
        l--, r--;
        int ans = 0;
        if(l<=r) {
            ans = pref[r] - pref[l];
        }
        else {
            swap(l, r);
            ans = suf[l] - suf[r];
        }
        cout << ans << nl;
    }
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}