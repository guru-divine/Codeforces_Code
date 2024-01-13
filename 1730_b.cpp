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

bool check(double mid, vi &pos, vi &time) {
    double l = INT_MIN, r = INT_MAX;
    fori(i, 0, sz(pos)-1) {
        l = max(l, pos[i] - (mid-time[i]));
        r = min(r, pos[i] + (mid-time[i]));
        if(l>r) return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vi pos(n), time(n);
    fori(i, 0, n-1) cin >> pos[i];
    fori(i, 0, n-1) cin >> time[i];
    vector<pii> pos_time(n);
    fori(i, 0, n-1) pos_time[i] = {pos[i], time[i]};
    sorti(pos_time);

    if(pos_time[0].F==pos_time[n-1].F) {
        cout << pos_time[0].F << nl;
        return;
    }

    double lo = 0, hi = 1e9;
    double ans = 0;
    while(lo<=hi) {
        if((hi-lo)*1e8 < 1) break;
        double mid = (lo+hi)/2;
        if(check(mid, pos, time)) {
            ans = mid;
            hi = mid-0.0000001;
        }
        else lo = mid+0.0000001;
    }
    lo = INT_MIN, hi = INT_MAX;
    fori(i, 0, n-1) {
        lo = max(lo, pos[i]-(ans-time[i]));
        hi = min(hi, pos[i]+(ans-time[i]));
    }
    double final_pos = (lo+hi)/2;
    cout << setprecision(15) << final_pos << nl;
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