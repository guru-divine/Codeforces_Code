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

int dp(int idx, int flag, int k, int z, vi &point, vector<vi> &memo) {
    if(k<0) return 0;
    else if(flag==2 || z<0 || idx<0 || idx>=point.size()) return -1e12;
    else if(memo[k][z]!=-1) return memo[k][z];

    int ans = 0;
    ans = max(ans, dp(idx-1, flag+1, k-1, z-1, point, memo) + point[idx]);
    ans = max(ans, dp(idx+1, 0, k-1, z, point, memo) + point[idx]);

    return memo[k][z] = ans; 
}

void solve() {
    int n, k, z; cin >> n >> k >> z;
    vi point(n);
    fori(i, 0, n-1) cin >> point[i];

    vector<vi> memo(k+2, vi(z+2, -1));

    dp(0, 0, k, z, point, memo);
    cout << memo[k][z] << nl;
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