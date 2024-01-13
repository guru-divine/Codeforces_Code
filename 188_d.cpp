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
#define mod 100000000
#define fori(i,a,b) for(int i=a; i<=b; ++i)
#define ford(i,a,b) for(int i=a; i>=b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reversei(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()-1) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()-1) {cout << arr[i] << nl;}
using namespace std; 

int n1, n2, k1, k2;

int dp(int idx1, int idx2, bool flag, vector<vector<vi>> &memo) {
    if(idx1==n1 && idx2==n2) return 1;
    else if(idx1>n1 || idx2>n2) return 0;
    else if(memo[idx1][idx2][flag]!=-1) return memo[idx1][idx2][flag];

    int ans = 0;
    if(flag==0) {
        fori(i, 1, k1) {
            ans = (ans + dp(idx1+i, idx2, 1, memo))%mod;
        } 
    }
    else {
        fori(i, 1, k2) {
            ans = (ans + dp(idx1, idx2+i, 0, memo))%mod;
        }
    }

    return memo[idx1][idx2][flag] = ans;
}

void solve() {
    cin >> n1 >> n2 >> k1 >> k2;
    vector<vector<vi>> memo(n1+5, vector<vi>(n2+5, vi(2, -1)));
    int ans = (dp(0, 0, 0, memo)+dp(0, 0, 1, memo))%mod;
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