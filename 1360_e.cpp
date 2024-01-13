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
#define ford(i,a,b) for(int i=a; i<b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

bool check(int row, int col, int n, vs &adj, vector<vi> &dp) {
    if(adj[row][col]=='0') return false;
    if(row==n-1 || col==n-1) return dp[row][col]=(adj[row][col]-'0');
    if(dp[row][col]==1) return true;
    else if(dp[row][col]==0) return false;

    int num1 = check(row+1, col, n, adj, dp);
    int num2 = check(row, col+1, n, adj, dp);

    return dp[row][col] = num1|num2;
}

void solve() {
    int n; cin >> n;
    vector<string> adj(n);
    vector<vi> dp(n, vi(n, -1));

    fori(i, 0, n) {
        cin >> adj[i];
    }

    fori(i, 0, n) {
        fori(j, 0, n) {
            if(adj[i][j]=='1') {
                if(check(i, j, n, adj, dp)==false) {
                    cout << "NO" << nl;
                    return;
                }
            } 
        }
    }
    cout << "YES" << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}