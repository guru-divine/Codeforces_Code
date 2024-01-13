//Author: DIVYA RAJ (aka guru_divine)
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
    int n, k; cin >> n >> k;
    vi arr(n+1);
    
    int num = (1<<6);
    vector<vi> memo(n+2, vi(num+1, 0));
    fori(i, 0, 63) {
        int bitCnt = __builtin_popcount(i);
        if(bitCnt==k) memo[0][i]=1;
        else memo[0][i]=0;
    }
    fori(i, 1, n) {
        cin >> arr[i];
        fori(j, 0, 63) {
            memo[i][j] = (memo[i-1][j] + memo[i-1][j & arr[i]])%mod;
        }
    }

    int ans = memo[n][63];
    if(k==6) ans--;

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
