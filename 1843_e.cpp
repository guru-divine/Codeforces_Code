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
    int n, m; cin >> n >> m;
    vi vis(n+1, 0);
    vector<pii> range(m);
    fori(i, 0, m) {
        cin >> range[i].F >> range[i].S;
    }
    int q; cin >> q;
    vi query(q);
    fori(i, 0, q) {
        cin >> query[i];
    }

    int lo=1, hi=q;
    int ans = -1;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        vi arr(n+1, 0);
        vi pref(n+1, 0);
        fori(i, 0, mid) {
            arr[query[i]]=1;
        }
        fori(i, 1, n+1) pref[i] = arr[i]+pref[i-1];
        int flag=0;
        fori(i, 0, m) {
            int l = range[i].F;
            int r = range[i].S;
            if((pref[r]-pref[l-1])*2>(r-l+1)) {
                ans = mid;
                hi = mid-1;
                flag=1;
                break;
            }
        }
        if(!flag) lo = mid+1;
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