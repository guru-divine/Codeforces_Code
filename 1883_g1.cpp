//Author: DIVYA RAJ (aka guru_divine)
#include <bits/stdc++.h>
#define ll long long
#define int unsigned long long
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

void solve(vi &twoPow) {
    int n, m; cin >> n >> m;
    vi arr(n), brr(n);
    arr[0] = 1;
    fori(i, 1, n-1) cin >> arr[i];
    fori(i, 0, n-1) cin >> brr[i];
    sorti(arr);
    sorti(brr);
    int ans = 0;
    int prevI=0, prevJ=0;
    int i=0, j=0;
    while(i<n && j<n) {
        if(brr[j]<=arr[i]) j++;
        else {
            ans += (j-prevJ);
            i++, j++;
            prevJ = j;
            prevI = i;
        }
    }
    ans += (n-prevI);
    ans/=2;
    cout << ans << nl;
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vi twoPow;
    int num = 1;
    fori(i, 0, 32) {
        twoPow.pb(num);
        num *= 2;
    }
    int t=1;
    cin >> t;
    while(t--) solve(twoPow);
    return 0;
}