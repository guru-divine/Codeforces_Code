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

void solve() {
    int k; cin >> k;
    // k;
    int lo = 1, hi = 50;
    int ans = -1;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        int num = binPow(mid, 10);
        if(num>=k) {
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    lo = 0, hi = 10;
    int freq1 = ans-1, freq2 = ans;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        int num = binPow(freq1, mid)*binPow(freq2, 10-mid);
        if(num>=k) {
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    string s;
    string init = "codeforces";

    fori(i, 0, 10) {
        if(i<ans) {
            fori(j, 0, freq1) s += init[i];
        }
        else fori(j, 0, freq2) s += init[i];
    }

    cout << s << nl;
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