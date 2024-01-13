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

int dp(int num, int &n, int k, vector<vi> &memo) {
    if(num>n) return 0;
    if(k==0) return 1;
    if(memo[num][k]!=-1) return memo[num][k];

    int ans = 0;
    for(int i=num; i<=n; i+=num) {
        ans = (ans + dp(i, n, k-1, memo))%mod;
    }

    return memo[num][k] = ans;
} 

void solve() {
    int n, k; cin >> n >> k;
    vector<vi> memo(n+1, vi(k+1, -1));
    fori(i, 1, n+1) {
        dp(i, n, k, memo);
    }
    int ans = memo[1][k];

    cout << ans << nl;
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}