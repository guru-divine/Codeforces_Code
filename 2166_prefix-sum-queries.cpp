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

class node {
    public:
        int mSum, lSum, rSum, totSum;
};

node merge(node a, node b) {
    node ans;
    ans.totSum = a.totSum + b.totSum;
    ans.lSum = max(a.lSum, a.totSum+b.lSum);
    ans.rSum = max(b.rSum, b.totSum+a.rSum);
    ans.mSum = max({a.rSum+b.lSum, a.mSum, b.mSum});
    return ans;
}

void build(int idx, int l, int r, vi &arr, vector<node> &seg) {
    if(l==r) {
        seg[idx].mSum = seg[idx].lSum = seg[idx].rSum = seg[idx].totSum = arr[l];
        if(arr[l]<0) seg[idx].mSum = 0;
        return;
    }
    int mid = (l+r)/2;
    build(2*idx, l, mid, arr, seg);
    build(2*idx+1, mid+1, r, arr, seg);
    seg[idx] = merge(seg[2*idx], seg[2*idx+1]);
}

void change(int idx, int l, int r, int &pos, int &val, vector<node> &seg) {
    if(pos<l || pos>r) return;
    if(l==r) {
        seg[idx].mSum = seg[idx].lSum = seg[idx].rSum = seg[idx].totSum = val;
        if(val<0) seg[idx].mSum = 0;
        return;
    }
 
    int mid = (l+r)/2;
    change(2*idx, l, mid, pos, val, seg);
    change(2*idx+1, mid+1, r, pos, val, seg);
 
    seg[idx] = merge(seg[2*idx], seg[2*idx+1]);
 
}
 
node findMax(int idx, int l, int r, int lq, int rq, vector<node> &seg) {
    if(lq>r || rq<l) return {0};
    if(lq<=l && r<=rq) {
        return seg[idx];
    }
 
    int mid = (l+r)/2;
    return merge(findMax(2*idx, l, mid, lq, rq, seg), findMax(2*idx+1, mid+1, r, lq, rq, seg));
}

void solve() {
    int n, q; cin >> n >> q;
    vi arr(n);
    vector<node> seg(4*n+10);
 
    fori(i, 0, n-1) cin >> arr[i];
 
    build(1, 0, n-1, arr, seg);
 
    while(q--) {
        int ch; cin >> ch;
        //change of data at idx pos
        if(ch==1) {
            int pos, val; cin >> pos >> val;
            pos--;
            change(1, 0, n-1, pos, val, seg);
        }
        //max array subsum from(l, r)
        else {
            int l, r; cin >> l >> r;
            l--, r--;
            node ans = findMax(1, 0, n-1, l, r, seg);
            cout << ans.mSum << nl;
        }
    }
}

signed main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}