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

class node {
    public:
        short cur;
        short val[101];
};

void build(int idx, int l, int r, vector<short> &arr, vector<node> &seg) {
    if(l==r) {
        seg[idx].cur = arr[l];
        return;
    }

    int mid = (l+r)/2;
    build(2*idx, l, mid, arr, seg);
    build(2*idx+1, mid+1, r, arr, seg);
}

void updateArray(int par, int child, vector<node> &seg) {
    for(short i=1; i<=100; ++i) {
        if(seg[child].val[i]!=0) {
            if(seg[par].val[seg[child].val[i]]!=0) seg[child].val[i] = seg[par].val[seg[child].val[i]];
        }
    }
    for(short i=1; i<=100; ++i) {
        if(seg[par].val[i]!=0) seg[child].val[i] = seg[par].val[i];
    }
}

void change(int idx, int l, int r, int lq, int rq, int oldVal, int newVal, vector<node> &seg) {
    if(l!=r) {
        updateArray(idx, 2*idx, seg);
        updateArray(idx, 2*idx+1, seg);
    }
    if(l>rq || r<lq) return;
    if(lq<=l && r<=rq) {
        seg[idx].val[oldVal] = newVal;
        for(short i=1; i<=100; ++i) if(seg[idx].val[i]==oldVal) seg[idx].val[i] = newVal;
        return;
    }
    int mid = (l+r)/2;
    change(2*idx, l, mid, lq, rq, oldVal, newVal, seg);
    change(2*idx+1, mid+1, r, lq, rq, oldVal, newVal, seg);
}

void findVal(int idx, int l, int r, vector<node> &seg) {
    if(l!=r) {
        updateArray(idx, 2*idx, seg);
        updateArray(idx, 2*idx+1, seg);
    }

    if(l==r) {
        if(seg[idx].val[seg[idx].cur]!=0) cout << seg[idx].val[seg[idx].cur] << " ";
        else cout << seg[idx].cur << " ";
        return;
    }

    int mid = (l+r)/2;
    findVal(2*idx, l, mid, seg);
    findVal(2*idx+1, mid+1, r, seg);
}

void solve() {
    int n; cin >> n;
    vector<short> arr(n);
    vector<node> seg(4*n+10);

    fori(i, 0, n) cin >> arr[i];
    build(1, 0, n-1, arr, seg);

    int q; cin >> q;
    while(q--) {
        // findVal(1, 0, n-1, seg);
        // cout << nl;
        int l, r, oldVal, newVal; cin >> l >> r >> oldVal >> newVal;
        l--, r--;
        change(1, 0, n-1, l, r, oldVal, newVal, seg);
    }
    findVal(1, 0, n-1, seg);
    cout << nl;
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