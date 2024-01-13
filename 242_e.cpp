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
        int lazy = 0, sum = 0;
        int xori[32]={0};
};

void push(int idx, int l, int r, vector<node> &seg) {
    if(seg[idx].lazy) {
        seg[idx].sum = 0;
        fori(i, 0, 31) {
            if((seg[idx].lazy>>i) & 1) {
                seg[idx].xori[i] = r-l+1 - seg[idx].xori[i];
            }
            seg[idx].sum += ((1<<i)*seg[idx].xori[i]);
        }
        if(l!=r) seg[2*idx].lazy ^= seg[idx].lazy, seg[2*idx+1].lazy ^= seg[idx].lazy;
        seg[idx].lazy = 0;
    }
}

void build(int idx, int l, int r, vi &arr, vector<node> &seg) {
    if(l==r) {
        fori(i, 0, 31) {
            seg[idx].xori[i] = ((arr[l]>>i) & 1);
        }
        seg[idx].sum = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*idx, l, mid, arr, seg);
    build(2*idx+1, mid+1, r, arr, seg);
    fori(i, 0, 31) seg[idx].xori[i] = seg[2*idx].xori[i] + seg[2*idx+1].xori[i];
    seg[idx].sum = seg[2*idx].sum + seg[2*idx+1].sum;
}

void update(int idx, int l, int r, int lq, int rq, int x, vector<node> &seg) {
    push(idx, l, r, seg);
    if(lq>r || rq<l) return;
    if(lq<=l && r<=rq) {
        seg[idx].lazy = x;
        push(idx, l, r, seg);
        return;
    }
    int mid = (l+r)/2;
    update(2*idx, l, mid, lq, rq, x, seg);
    update(2*idx+1, mid+1, r, lq, rq, x, seg);
    fori(i, 0, 31) seg[idx].xori[i] = seg[2*idx].xori[i] + seg[2*idx+1].xori[i];
    seg[idx].sum = seg[2*idx].sum + seg[2*idx+1].sum;
}

int findSum(int idx, int l, int r, int lq, int rq, vector<node> &seg) {
    push(idx, l, r, seg);
    if(lq>r || rq<l) return 0;
    if(lq<=l && r<=rq) return seg[idx].sum;
    int mid = (l+r)/2;
    return (findSum(2*idx, l, mid, lq, rq, seg) + findSum(2*idx+1, mid+1, r, lq, rq, seg));
}

void solve() {
    int n; cin >> n;
    vi arr(n);
    vector<node> seg(4*n+100);
    fori(i, 0, n-1) cin >> arr[i];
    build(1, 0, n-1, arr, seg);

    int q; cin >> q;
    while(q--) {
        int ch, l, r; cin >> ch >> l >> r;
        l--, r--;
        if(ch==1) {
            cout << findSum(1, 0, n-1, l, r, seg) << nl;
            
        }
        else {
            int x; cin >> x;
            update(1, 0, n-1, l, r, x, seg);
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