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

int findGreaterSmaller(int idx, int l, int r, int lq, int rq, vi &seg) {
    if(lq>r || rq<l) return 0; 
    if(lq<=l && r<=rq) return seg[idx];

    int mid = (l+r)/2;
    return findGreaterSmaller(2*idx, l, mid, lq, rq, seg)+findGreaterSmaller(2*idx+1, mid+1, r, lq, rq, seg);
}

void insert(int idx, int l, int r, int pos, vi &seg) {
    if(pos<l || pos>r) return;
    if(l==r) {
        seg[idx]=1;
        return;
    }

    int mid = (l+r)/2;
    insert(2*idx, l, mid, pos, seg);
    insert(2*idx+1, mid+1, r, pos, seg);
    seg[idx] = seg[2*idx]+seg[2*idx+1];
}

void solve() {
    int n; cin >> n;
    vi arr(n), brr(n);
    fori(i, 0, n-1) {
        cin >> arr[i];
        brr[i] = arr[i];
    }
    vi segBig(4*n+10, 0), segSmall(4*n+10, 0);
    sorti(brr);
    mapi mp;
    fori(i, 0, n-1) {
        mp[brr[i]] = i;
    }
    brr.clear();
    vector<pii> ans(n);
    fori(i, 0, n-1) {
        int val = mp[arr[i]];
        ans[i].F = findGreaterSmaller(1, 0, n-1, val, n-1, segBig);
        insert(1, 0, n-1, val, segBig);
    }
    ford(i, n-1, 0) {
        int val = mp[arr[i]];
        ans[i].S = findGreaterSmaller(1, 0, n-1, 0, val, segSmall);
        insert(1, 0, n-1, val, segSmall);
    }
    int weakness=0;
    fori(i, 0, n-1) {
        weakness += (ans[i].F*ans[i].S);
        // cout << ans[i].F << " " << ans[i].S << nl;
    }

    cout << weakness << nl;
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