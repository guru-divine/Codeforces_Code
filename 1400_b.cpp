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
    int cnt[2], wt[2];
    int p, f; cin >> p >> f;
    vector<pii> weight_cnt(2);
    for(int i=0; i<2; ++i) cin >> weight_cnt[i].S;
    for(int i=0; i<2; ++i) cin >> weight_cnt[i].F;
    sorti(weight_cnt);
    int ans = 0;
    for(int i=0; i<=min(weight_cnt[0].S, p/weight_cnt[0].F); ++i) {
        int j = min(weight_cnt[1].S, (p - i*weight_cnt[0].F)/weight_cnt[1].F);
        int k = min(weight_cnt[0].S - i, f/weight_cnt[0].F);
        int l = min(weight_cnt[1].S - j, (f - k*weight_cnt[0].F)/weight_cnt[1].F);
        ans = max(ans, i+j+k+l);
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