//Author: DIVYA RAJ
#include <bits/stdc++.h>
#define ll long long
#define int unsigned long long
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
    int n, c; cin >> n >> c;
    // int w;
    double sum = 0, sqrSum=0;
    vi arr(n);
    fori(i, 0, n) {
        cin >> arr[i];
        sum += arr[i];
        sqrSum += (arr[i]*arr[i]);
    }

    // int w = (sqrtl(sum*sum + n*(c-sqrSum)) - sum)/(2*n);
    double w = sqrtl((sum*sum)/(4*n*n) + (c-sqrSum)/(4*n)) - sum/(2*n);
    double ans = round(w);
    cout << setprecision(20) << ans << nl;
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