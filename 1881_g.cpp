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

class node {
    public:
        int lazy = 0, pal = 0;
        vi left, right;
        node() : left(vi(2, -1)), right(vi(2, -1)), pal(0), lazy(0) {}
        node(int x) : left({x, -1}), right({x, -1}), pal(0), lazy(0) {}
        friend node operator+(const node &a, const node &b) {
            if(a.left[0]==-1 && a.left[1]==-1) return b;
            if(b.left[0]==-1 && b.left[1]==-1) return a;
            node temp;
            temp.left[0] = a.left[0], temp.right[0] = b.right[0];
            temp.left[1] = (a.left[1]!=-1) ? a.left[1] : b.left[0];
            temp.right[1] = (b.right[1]!=-1) ? b.right[1] : a.right[0];
            temp.lazy = 0;
            temp.pal = a.pal | b.pal | (a.right[0]==b.left[0]) |
                        (a.right[1]!=-1 && a.right[1]==b.left[0]) | (b.left[1]!=-1 && a.right[0]==b.left[1]);
            return temp;
        }
};

void push(int idx, int l, int r, vector<node> &seg) {
    if(seg[idx].lazy) {
        seg[idx].left[0] = (seg[idx].left[0] + seg[idx].lazy)%26;
        seg[idx].right[0] = (seg[idx].right[0] + seg[idx].lazy)%26;
        if(seg[idx].left[1]!=-1) seg[idx].left[1] = (seg[idx].left[1] + seg[idx].lazy)%26;
        if(seg[idx].right[1]!=-1) seg[idx].right[1] = (seg[idx].right[1] + seg[idx].lazy)%26;
    }
    if(l!=r) {
        seg[2*idx].lazy = (seg[2*idx].lazy + seg[idx].lazy)%26;
        seg[2*idx+1].lazy = (seg[2*idx+1].lazy + seg[idx].lazy)%26;
    }
    seg[idx].lazy = 0;
}

void build(int idx, int l ,int r, vi &arr, vector<node> &seg) {
    if(l==r) {
        seg[idx] = node(arr[l]);
        return;
    }
    int mid = (l+r)/2;
    build(2*idx, l, mid, arr, seg);
    build(2*idx+1, mid+1, r, arr, seg);
    seg[idx] = seg[2*idx] + seg[2*idx+1];
}

void change(int idx, int l, int r, int lq, int rq, int x, vector<node> &seg) {
    push(idx, l, r, seg);
    if(lq>r || rq<l) return;
    if(lq<=l && r<=rq) {
        seg[idx].lazy = x;
        push(idx, l, r, seg);
        return;
    }
    int mid = (l+r)/2;
    change(2*idx, l, mid, lq, rq, x, seg);
    change(2*idx+1, mid+1, r, lq, rq, x, seg);
    seg[idx] = seg[2*idx] + seg[2*idx+1];
}

node query(int idx, int l, int r, int lq, int rq, vector<node> &seg) {
    push(idx, l, r, seg);
    if(lq>r || rq<l) return node();
    if(lq<=l && r<=rq) return seg[idx];
    int mid = (l+r)/2;
    return query(2*idx, l, mid, lq, rq, seg) + query(2*idx+1, mid+1, r, lq, rq, seg);
}

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vi arr(n);
    fori(i, 0, n-1) arr[i] = s[i]-'a';
    vector<node> seg(4*n+100);
    build(1, 0, n-1, arr, seg);
    while(q--) {
        int ch, l, r; cin >> ch >> l >> r;
        l--, r--;
        if(ch==1) {
            int x; cin >> x;
            change(1, 0, n-1, l, r, x, seg);
        }
        else {
            int ans = query(1, 0, n-1, l, r, seg).pal;
            if(ans==0) cout << "YES" << nl;
            else cout << "NO" << nl;
        }
    }
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