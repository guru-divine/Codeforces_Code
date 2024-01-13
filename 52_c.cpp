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
        int val, inc=0;
};

void push(int idx, int l, int r, vector<node> &seg) {
    if(seg[idx].inc) {
        seg[idx].val += seg[idx].inc;
        if(l!=r) {
            seg[2*idx].inc += seg[idx].inc;
            seg[2*idx+1].inc += seg[idx].inc;
        }
        seg[idx].inc = 0;
    }
}

void build(int idx, int l, int r, vi &arr, vector<node> &seg) {
    if(l==r) {
        seg[idx].val = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*idx, l, mid, arr, seg);
    build(2*idx+1, mid+1, r, arr, seg);
    seg[idx].val = min(seg[2*idx].val, seg[2*idx+1].val);
}

void update(int idx, int l, int r, int lq, int rq, int val, vector<node> &seg) {
    push(idx, l, r, seg);
    if(lq>r || rq<l) return;
    if(lq<=l && r<=rq) {
        seg[idx].inc = val;
        push(idx, l, r, seg);
        return;
    }
    int mid = (l+r)/2;
    update(2*idx, l, mid, lq, rq, val, seg);
    update(2*idx+1, mid+1, r, lq, rq, val, seg);
    seg[idx].val = min(seg[2*idx].val, seg[2*idx+1].val);
}

int findMin(int idx, int l, int r, int lq, int rq, vector<node> &seg) {
    push(idx, l, r, seg);
    if(lq>r || rq<l) return 1e12;
    if(lq<=l && r<=rq) return seg[idx].val;
    int mid = (l+r)/2;
    return min(findMin(2*idx, l, mid, lq, rq, seg), findMin(2*idx+1, mid+1, r, lq, rq, seg));
}

void solve() {
    int n; cin >> n;
    vi arr(n);
    vector<node> seg(4*n+100);
    fori(i,0, n-1) cin >> arr[i];
    build(1, 0, n-1, arr, seg);

    int q; cin >> q;
    cin.ignore();
    while(q--) {
        string s; getline(cin, s);
        istringstream iss(s);
        int l, r, x;
        if(count(s.begin(), s.end(), ' ')==1) {
            iss >> l >> r;
            if(l<=r) cout << findMin(1, 0, n-1, l, r, seg) << '\n';
            else cout << min(findMin(1, 0, n-1, 0, r, seg), findMin(1, 0, n-1, l, n-1, seg)) << '\n';
        } else {
            iss >> l >> r >> x;
            if(l<=r) update(1, 0, n-1, l, r, x, seg);
            else update(1, 0, n-1, 0, r, x, seg), update(1, 0, n-1, l, n-1, x, seg);
        }
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