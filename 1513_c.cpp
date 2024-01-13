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

int binPow(int a, int n) {
    int ans = 1;
    while(n) {
        if(n&1) ans = (ans*a);
        a = (a*a);
        n >>= 1;
    }
    return ans;
}

int cntLen(int dig, int m) {
    if(m<10-dig) return 0;

    int cnt = 2;
    m-=(10-dig);

    int lo=0, hi=10;
    int ans = 0;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        if(binPow(mid, 9)<=m) {
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    
}

void solve() {
    int num, m; cin >> num >> m;
    while(num) {
        int dig = num%10;
        num/=10;
    }
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