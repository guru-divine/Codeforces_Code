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
    seg[idx] = __gcd(seg[2*idx], seg[2*idx+1]);
}

void findGcd(int idx, int l, int r, int lq, int rq, int &ans, vi &seg) {
    if(l>rq || r<lq) return;
    if(lq<=l && r<=rq) {
        ans = __gcd(ans, seg[idx]);
        return;
    }

    int mid = (l+r)/2;
    findGcd(2*idx, l, mid, lq, rq, ans, seg);
    findGcd(2*idx+1, mid+1, r, lq, rq, ans, seg);
}

void solve() {
    int n; cin >> n;
    vi arr(n), seg(4*n+10);
    vector<pii> st(n);
    fori(i, 0, n) {
        cin >> arr[i];
        st[i] = {arr[i], i};
    }
    sorti(st);

    build(1, 0, n-1, arr, seg);

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        l--, r--;
        int gcd = 0;
        findGcd(1, 0, n-1, l, r, gcd, seg);

        int ans = r-l+1, freed = 0;
        // auto it = lower_bound(st.begin(), st.end(), {gcd, l});
        pii p = {gcd, l};
        auto it1 = lower_bound(all(st), p);
        p = {gcd, r};
        auto it2 = upper_bound(all(st), p);
        if(it1==it2 || it1->F>gcd) freed = 0;
        // it2--;
        else freed = (it2-it1);

        ans -= freed;
        cout << ans << nl;
    }
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