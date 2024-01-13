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

bool check(int k, vector<pii> &seg) {
    int minPos=0, maxPos=0;
    fori(i, 0, sz(seg)-1) {
        if(seg[i].S<minPos && minPos-seg[i].S>k) return false;
        else if(seg[i].F>maxPos && seg[i].F-maxPos>k) return false;

        if(seg[i].F<=maxPos) {
            minPos = max(minPos-k, seg[i].F);
            if(seg[i].S>maxPos && seg[i].S>maxPos+k) maxPos = maxPos+k;
            else maxPos = seg[i].S;
        }
        else {
            minPos = seg[i].F;
            if(seg[i].S>maxPos && seg[i].S>maxPos+k) maxPos = maxPos+k;
            else maxPos = seg[i].S;
        }

    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<pii> seg(n);
    fori(i, 0, n-1) cin >> seg[i].F >> seg[i].S;

    int lo=0, hi=1e10;
    int ans = 0;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        if(check(mid, seg)) {
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
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