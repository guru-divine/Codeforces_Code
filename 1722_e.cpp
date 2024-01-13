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
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std; 

void solve() {
    int n, q; cin >> n >> q;
    vector<vi> arr(1005, vi(1005)), pref(1005, vi(1005));
    fori(i, 0, n-1) {
        int l, r; cin >> l >> r;
        arr[l][r] += (l*r);
    }
    for(int i=1; i<1005; ++i) {
        for(int j=1; j<1005; ++j) {
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + arr[i][j];
        }
    }
    while(q--) {
        int hs, ws, hb, wb; cin >> hs >> ws >> hb >> wb;
        int ans = pref[hb-1][wb-1] - pref[hb-1][ws] - pref[hs][wb-1] + pref[hs][ws];
        cout << ans << nl;
    }

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