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

int dp(int idx, int health, vi &arr, vi &memo, multiset<int> &mst) {
    if(idx<0) return 0;
    if(memo[idx]!=-1) return memo[idx];

    int ans=0;

    if(arr[idx]+health>=0) {
        mst.insert(arr[idx]);
        ans = max(ans, dp(idx-1, health+arr[idx], arr, memo, mst)+1);
    }
    else {
        int mini = *mst.begin();
        if(mini<arr[idx]) {
            mst.insert(arr[idx]);
            mst.erase(mst.find(mini));
            ans = max(ans, dp(idx-1, health + arr[idx] - mini, arr, memo, mst));
        }
        else ans = max(ans, dp(idx-1, health, arr, memo, mst));
    }

    return memo[idx]=ans;
}

void solve() {
    int n; cin >> n;
    vi arr(n);
    fori(i, 0, n) cin >> arr[i];
    reversei(arr);
    multiset<int> mst;

    vi memo(n+2, -1);

    int health=0;
    cout << dp(n-1, health, arr, memo, mst) << nl;
    // printS(memo);
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