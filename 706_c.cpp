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

int dp(int idx, bool flag, vs &str, vi &cost, vector<vi> &memo) {
    if(idx>=sz(cost)) return 0;
    else if(memo[idx][flag]!=-1) return memo[idx][flag];

    int ans = 1e15;
    if(str[idx-1]<=str[idx]) ans = min(ans, dp(idx+1, 0, str, cost, memo));
    reversei(str[idx]);
    if(str[idx-1]<=str[idx]) ans = min(ans, dp(idx+1, 1, str, cost, memo) + cost[idx]);
    reversei(str[idx]);

    return memo[idx][flag] = ans;
}

void solve() {
    int n; cin >> n;
    vi cost(n+1, 0);
    fori(i, 1, n) cin >> cost[i];
    vs str(n+1);
    str[0] = 'A';
    fori(i, 1, n) cin >> str[i];

    vector<vi> memo(n+10, vi(2, -1));
    dp(1, 0, str, cost, memo);
    int ans = memo[1][0];
    if(ans==1e15) ans = -1;
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