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

int dp(int idx, int time, vi &arr, vector<vi> &memo) {
    if(idx==sz(arr)) return 0;
    else if(time>2*sz(arr)+5) return 1e15;
    else if(memo[idx][time]!=-1) return memo[idx][time];

    int ans = min(dp(idx, time+1, arr, memo), dp(idx+1, time+1, arr, memo) + abs(arr[idx]-time));

    return memo[idx][time] = ans;
}

void solve() {
    int n; cin >> n;
    vi arr(n);
    fori(i, 0, n-1) {
        cin >> arr[i];
    }
    sorti(arr);
    vector<vi> memo(n+10, vi(2*n+10, -1));

    int ans = dp(0, 1, arr, memo);
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