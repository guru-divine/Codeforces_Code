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

void solve() {
    int n; cin >> n;
    vi arr(n);
    vector<vi> memo(n+2, vi(2, 0));

    fori(i, 0, n) {
        cin >> arr[i];
        if(arr[i]==1 || arr[i]==3) memo[i][0]=1;
        if(arr[i]==2 || arr[i]==3) memo[i][1]=1;
    }

    fori(i, 1, n) {
        if(memo[i][0]==0) memo[i][0] = max(memo[i-1][0], memo[i-1][1]);
        else memo[i][0] += memo[i-1][1];

        if(memo[i][1]==0) memo[i][1] = max(memo[i-1][0], memo[i-1][1]);
        else memo[i][1] += memo[i-1][0]; 
    }

    int ans = max(memo[n-1][0], memo[n-1][1]);
    ans = n-ans;

    cout << ans << nl;
}

signed main() {
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}