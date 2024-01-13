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
#define mod 1000000007
#define fori(i,a,b) for(int i=a; i<=b; ++i)
#define ford(i,a,b) for(int i=a; i>=b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reversei(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std; 

void solve() {
    int n, k; cin >> n >> k;
    vi first(n), experience(n);
    fori(i, 0, n-1) cin >> first[i];
    fori(i, 0, n-1) cin >> experience[i];
    vi pref(n, 0), maxExp(n, 0);
    fori(i, 0, n-1) {
        pref[i] = first[i];
        maxExp[i] = experience[i];
        if(i) {
            pref[i] += pref[i-1];
            maxExp[i] = max(maxExp[i], maxExp[i-1]);
        }
    }
    int ans = 0;
    fori(i, 0, n-1) {
        if(i+1>k) break;
        ans = max(ans, pref[i] + (k - (i+1))*maxExp[i]);
    }
    cout << ans << nl;
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}