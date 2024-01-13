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
    multiset<pii> mst;
    fori(i, 0, n) {
        int a, b; cin >> a >> b;
        mst.insert({b, a});
    }

    int cnt = 0;
    int ans = 0;
    while(!mst.empty()) {
        auto it = mst.begin();
        if(cnt>=it->F) {
            ans += it->S;
            cnt += it->S;
            mst.erase(it);
            // continue;
        }
        else {
            auto itE = mst.end();
            itE--;
            if(itE->S <= it->F-cnt) {
                cnt += itE->S;
                ans += 2*itE->S;
                mst.erase(itE);
            }
            else {
                int diff = it->F-cnt;
                mst.insert({itE->F, itE->S-diff});
                mst.erase(itE);
                cnt += diff;
                ans += 2*diff;
            }
        }
        // cout << cnt << nl;
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