//Author: DIVYA RAJ (aka guru_divine)
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define nl "\n"
#define pb push_back
#define F first
#define S second
#define sz(arr) (int)arr.size()
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

int dp(int idx, int mex, vi &arr, vi &f, vector<vi> &memo) {
    if(mex==0) return 0;
    if(idx==-1 && mex!=0) return 1e12;

    if(memo[idx][mex]!=-1) return memo[idx][mex];

    int ans = 1e12;
    ans = min(ans, dp(idx-1, mex, arr, f, memo));
    ans = min(ans, dp(idx-1, arr[idx], arr, f, memo) + (f[idx]-1)*mex + arr[idx]);

    return memo[idx][mex] = ans;
}

int mexFind(vi const& A) {
    set<int> b(A.begin(), A.end());

    int result = 0;
    while (b.count(result))
        ++result;
    return result;
}

void solve() {
    int n; cin >> n;
    mapi mp;
    fori(i, 0, n) {
        int x; cin >> x;
        mp[x]++;
    }
    vi arr, f;
    for(auto it: mp) {
        arr.pb(it.F);
        f.pb(it.S);
    }
    // printS(arr); printS(f);

    int mex = mexFind(arr);
    vector<vi> memo(sz(arr)+1, vi(mex+5, -1));

    int idx = upper_bound(all(arr), mex) - arr.begin() - 1;
    int ans = dp(idx, mex, arr, f, memo);

    cout << ans << nl;
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