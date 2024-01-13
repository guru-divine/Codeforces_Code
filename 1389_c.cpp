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
    string s; cin >> s;
    int n = sz(s);
    vi cnt(10, 0);
    fori(i, 0, sz(s)) {
        cnt[s[i]-'0']++;
    }
    sortd(cnt);

    int ans = 0;
    fori(i, 0, 10) {
        fori(j, 0, 10) {
            if(i==j) continue;
            int curAns=0;
            for(int k=0; k<sz(s); ++k) {
                if(curAns%2==0 && s[k]-'0'==i) curAns++;
                else if(curAns%2==1 && s[k]-'0'==j) curAns++;
            }
            if(curAns%2==1) curAns--;
            ans = max(ans, curAns);
        }
    }
    ans = max(ans, cnt[0]);
    ans = max(ans, 2*1LL);
    cout << n-ans << nl;
}

signed main() {
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}