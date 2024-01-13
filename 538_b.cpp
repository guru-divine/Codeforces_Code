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
    vi arr;
    int maxi = 0;
    while(n) {
        arr.pb(n%10);
        maxi = max(maxi, n%10);
        n/=10;
    }
    reversei(arr);
    vector<pii> brr;
    string s;
    fori(i, 0, sz(arr)) {
        brr.pb({arr[i], i});
        s.pb('1');
    }
    sorti(brr);
    int idx = 0;
    fori(i, 0, sz(brr)) {
        if(brr[i].F==0) {
            s[brr[i].S]='0';
            idx++;
        }
        else break;
    }

    cout << maxi << nl;
    int val = 0;
    while(maxi--) {
        while(idx<sz(arr)) {
            if(brr[idx].F==val) {
                s[brr[idx].S]='0';
                idx++;
            }
            else break;
        }
        val++;
        int ans = stoi(s);
        cout << ans << " ";
    }

}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}