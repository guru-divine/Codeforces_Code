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

int n, m, k;

int prefDiff(int idx, vi &pref) {
    int num1 = (idx+m>sz(pref))?0:pref[idx+m-1];
    int num2 = (idx-1>=0)?pref[idx-1]:0;
    return (num1-num2);
}

int dp(int idx, int ki, vi &pref, vector<vi> &memo) {
    if(idx==n) return 0;
    else if(idx>n) return -1e12;
    else if(ki==0) return 0;
    else if(memo[idx][ki]!=-1) return memo[idx][ki];

    int ans = max(dp(idx+m, ki-1, pref, memo)+prefDiff(idx, pref), dp(idx+1, ki, pref, memo));
    return memo[idx][ki] = ans;
}

void solve() {
    cin >> n >> m >> k;
    vi arr(n), pref(n, 0);
    fori(i, 0, n-1) {
        cin >> arr[i];
        pref[i] = arr[i];
        if(i) pref[i] += pref[i-1];
    }

    vector<vi> memo(n+2, vi(k+2, -1));
    int ans = dp(0, k, pref, memo);
    cout << ans << nl;
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