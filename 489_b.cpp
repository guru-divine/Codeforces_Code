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
    vi boys(n);
    fori(i, 0, n) cin >> boys[i];

    int m; cin >> m;
    vi girls(m);
    fori(i, 0, m) cin >> girls[i];

    sorti(boys); sorti(girls);

    int i=0, j=0;
    int pair=0;
    while(i<n && j<m) {
        if(boys[i]>=girls[j]) {
            if(boys[i]-girls[j]<=1) {
                pair++;
                i++; j++;
            }
            else j++;
        }
        else {
            if(girls[j]-boys[i]<=1) {
                pair++;
                i++; j++;
            }
            else i++;
        }
    }

    cout << pair << nl;
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