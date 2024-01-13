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
        int val;
        int flag;
};

void build(int idx, int l, int r, vi &arr, vector<node> &seg) {
    if(l==r) {
        seg[idx].val = arr[l];
        seg[idx].flag=-1;
        return;
    }

    int mid = (l+r)/2;
    build(2*idx, l, mid, arr, seg);
    build(2*idx+1, mid+1, r, arr, seg);

    if(seg[2*idx].flag==-1 || seg[2*idx].flag==1) {
        seg[idx].val = seg[2*idx].val | seg[2*idx+1].val;
        seg[idx].flag = 0;
    } 
    else {
        seg[idx].val = seg[2*idx].val ^ seg[2*idx+1].val;
        seg[idx].flag = 1;
    }
}

void changeVal(int idx, int l, int r, int pos, int nVal, vector<node> &seg) {
    if(pos>r || pos<l) return;
    if(l==r) {
        seg[idx].val = nVal;
        return;
    }

    int mid = (l+r)/2;
    changeVal(2*idx, l, mid, pos, nVal, seg);
    changeVal(2*idx+1, mid+1, r, pos, nVal, seg);

    if(seg[2*idx].flag==-1 || seg[2*idx].flag==1) {
        seg[idx].val = seg[2*idx].val | seg[2*idx+1].val;
        seg[idx].flag = 0;
    } 
    else {
        seg[idx].val = seg[2*idx].val ^ seg[2*idx+1].val;
        seg[idx].flag = 1;
    }
}

int binPow(int a, int n) {
    int ans = 1;
    while(n) {
        if(n&1) ans = (ans*a);
        n/=2;
        a = (a*a);
    }
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    n = binPow(2, n);
    vi arr(n);
    fori(i, 0, n-1) cin >> arr[i];

    vector<node> seg(4*n + 100);
    build(1, 0, n-1, arr, seg);
    while(m--) {
        // cout << m << " ";
        int pos, nVal; cin >> pos >> nVal;
        pos--;
        changeVal(1, 0, n-1, pos, nVal, seg);
        cout << seg[1].val << nl;
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