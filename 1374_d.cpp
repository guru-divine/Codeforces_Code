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
    int n, k; cin >> n >> k;
    vi arr;
    fori(i, 0, n) {
        int x; cin >> x;
        x%=k;
        if(x) arr.pb(x);
    }
    sorti(arr);
    // printS(arr);
    if(sz(arr)==0) {
        cout << "0" << nl;
        return;
    }

    int num=arr[0], maxFreq=1;
    int freq=1;
    fori(i, 0, sz(arr)-1) {
        if(arr[i]==arr[i+1]) {
            freq++;
            if(freq>maxFreq) {
                num = arr[i];
                maxFreq = freq;
            }
        }
        else {
            freq=1;
        }
    }

    int ans = k*(maxFreq-1) + (k-num)+1;
    cout << ans << nl;
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