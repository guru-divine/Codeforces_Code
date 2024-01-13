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
    if(a.S==b.S) return (a.F<b.F);
    return (a.S<b.S);
}

void solve() {
    int n, r, avg; cin >> n >> r >> avg;
    vector<pii> arr(n);
    int gradeNeeded = avg*n;
    fori(i, 0, n) {
        cin >> arr[i].F >> arr[i].S;
        gradeNeeded -= arr[i].F;
    }
    sort(all(arr), cmp);

    if(gradeNeeded<=0) {
        cout << "0" << nl;
        return;
    }
    int i=0;
    int ans = 0;
    while(true) {
        if(gradeNeeded<=r-arr[i].F) {
            ans += (gradeNeeded*arr[i].S);
            break;
        }
        else {
            gradeNeeded -= r-arr[i].F;
            ans += (r-arr[i].F)*arr[i].S;
            i++;
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