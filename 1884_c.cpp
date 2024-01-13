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

void solve() {
    int n, m; cin >> n >> m;
    int maxCnt=0, curCnt=0;
    int val=-1;
    multiset<int> shuru, khatam;
    multiset<pii> mst;
    fori(i, 0, n-1) {
        int l, r; cin >> l >> r;
        shuru.insert(l), khatam.insert(r);
        mst.insert({l, -1});
        mst.insert({r, 1});
    }
    for(auto it: mst) {
        curCnt -= it.S;
        if(curCnt>maxCnt) {
            maxCnt = curCnt;
            val = it.F;
        }
    }
    if(shuru.upper_bound(val)!=shuru.end() || *khatam.begin()<val) {}
    else maxCnt = 0;
    cout << maxCnt << nl;
}

signed main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}