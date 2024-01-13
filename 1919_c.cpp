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
#define printS(arr) fori(i,0,arr.size()-1) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()-1) {cout << arr[i] << nl;}
using namespace std; 

void solve() {
    int n; cin >> n;
    vi arr(n);
    fori(i, 0, n-1) cin >> arr[i];
    
    vi a[2];
    a[0].pb(INT_MAX), a[1].pb(INT_MAX);
    
    int ans = 0;
    fori(i, 0, n-1) {
        int j = 0;
        if(a[0].back()<a[1].back()) j=1;
        if(arr[i]>a[j].back()) {
            a[!j].pb(arr[i]); ans++;
        }
        else if(a[j].back()>=arr[i] && arr[i]>a[!j].back()) {
            a[j].pb(arr[i]);
        }
        else {
            a[!j].pb(arr[i]);
        }
    }
    cout << ans << nl;
    // printS(a[0]);
    // printS(a[1]);
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