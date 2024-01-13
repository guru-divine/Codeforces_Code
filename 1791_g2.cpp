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

bool cmp(pii &a, pii &b) {
    if(a.F==b.F) return (a.S>b.S);
    return (a.F<b.F);
}

void solve() {
    int n, c; cin >> n >> c;
    vi arr(n);
    vi mini(n);
    fori(i, 0, n) {
        cin >> arr[i];
        mini[i] = min(arr[i]+(i+1), arr[i]+(n-i));
    }

    sorti(mini);
    vi pref(n);
    fori(i, 0, n) {
        pref[i] = mini[i];
        if(i) pref[i] += mini[i];
    }

    int maxAns=0;
    fori(i, 0, n) {
        int sum = arr[i]+(i+1);
        if(sum>c) continue;

        int curAns = 1;
        auto it = lower_bound(all(pref), c-sum);
        if(*it!=c-sum) {
            if(it==pref.begin()) {
                maxAns = max(maxAns, curAns);
                continue;
            }
            else it--;
        }

        curAns += (it-pref.begin());
        maxAns = max(maxAns, curAns);
    }

    cout << maxAns << nl;
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