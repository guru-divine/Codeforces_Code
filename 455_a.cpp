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

int dp(int idx, int &l, vector<pii> &arr, vi &memo) {
    if(idx<l) return 0;
    if(memo[idx]!=-1) return memo[idx];

    int ans = 0;
    ans = max(ans, dp(idx-1, l, arr, memo));
    ans = max(ans, (dp(idx-2, l, arr, memo)+(arr[idx].F*arr[idx].S)));

    return memo[idx] = ans;
}

void solve() {
    int n; cin >> n;
    un_mapi ump;
    fori(i, 0, n) {
        int x; cin >> x;
        ump[x]++;
    }

    vector<pii> arr;
    for(auto it: ump) {
        arr.pb({it.F, it.S});
    }
    ump.clear();
    sorti(arr);

    vector<pii> pos;

    int i=0;
    while(i<arr.size()) {
            int l=i, r=i;
            i++;
            while(i<arr.size()) {
                if(arr[i].F!=arr[i-1].F+1) {
                    break;
                }
                i++; r++;
            }
            pos.pb({l, r});
    }

    int ans = 0;
    vi memo(n+2, -1);
    fori(i, 0, sz(pos)) {
        int l=pos[i].F;
        int r = pos[i].S;

        if(l==r) ans += (arr[l].F*arr[l].S);
        else {
            ans += dp(r, l, arr, memo);
            
            fori(i, l, r+1) memo[i]=-1;
        }
    }

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