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

void build(int idx, int l, int r, string &s, vi &arr, vector<vi> &seg) {
    if(l==r) {
        seg[idx][s[l]-'0'] = arr[l];
        return;
    }

    int mid=(l+r)/2;
    build(2*idx, l, mid, s, arr, seg);
    build(2*idx+1, mid+1, r, s, arr, seg);

    seg[idx][0] = (seg[2*idx][0])^(seg[2*idx+1][0]);
    seg[idx][1] = (seg[2*idx][1])^(seg[2*idx+1][1]);
}

void change(int idx, int l, int r, int &lq, int &rq, vector<int> &arr, vector<vi> &seg) {
    if(l>rq || r<lq) return;

    if(lq<=l && r<=rq) {
        swap(seg[idx][0], seg[idx][1]);
        return;
    }

    int mid = (l+r)/2;
    change(idx*2, l, mid, lq, rq, arr, seg);
    change(idx*2+1, mid+1, r, lq, rq, arr, seg);

    seg[idx][0] = (seg[2*idx][0])^(seg[2*idx+1][0]);
    seg[idx][1] = (seg[2*idx][1])^(seg[2*idx+1][1]);
}


void solve() {
    int n; cin >> n;
    vi arr(n);
    vector<vi> seg(4*n+100, vi(2, 0));

    fori(i, 0, n) cin >> arr[i];
    string s; cin >> s;

    build(1, 0, n-1, s, arr, seg);

    int q; cin >> q;
    while(q--) {
        int ch; cin >> ch;

        if(ch==1) {
            int l, r; cin >> l >> r;
            l--, r--;
            change(1, 0, n-1, l, r, arr, seg);
        }
        else {
            bool num; cin >> num;
            cout << seg[1][num] << " ";
        }
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