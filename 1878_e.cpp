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

void build(int idx, int l, int r, vi &arr, vi &seg) {
    if(l==r) {
        seg[idx] = arr[l];
        return;
    }

    int mid = (l+r)/2;
    build(2*idx, l, mid, arr, seg);
    build(2*idx+1, mid+1, r, arr, seg);
    seg[idx] = (seg[2*idx] & seg[2*idx+1]);
}

int findVal(int idx, int l, int r, int lq, int rq, vi &arr, vi &seg) {
    if(l>rq || r<lq) return INT_MAX;
    if(lq<=l && r<=rq) return seg[idx];

    int mid = (l+r)/2;
    return (findVal(2*idx, l, mid, lq, rq, arr, seg) & findVal(2*idx+1, mid+1, r, lq, rq, arr, seg));
}

void solve() {
    int n; cin >> n;
    vi arr(n);
    fori(i, 0, n) {
        cin >> arr[i];
    }
    vi seg(4*n+100);
    build(1, 0, n-1, arr, seg);

    int q; cin >> q;
    while(q--) {
        int l, k; cin >> l >> k;
        l--;
        int lo = l, hi = n-1;
        int ans = -2;
        while(lo<=hi) {
            int mid = (lo+hi)/2;
            if(findVal(1, 0, n-1, l, mid, arr, seg)>=k) {
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        ans++;
        cout << ans << " ";
    }
    cout << nl;
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