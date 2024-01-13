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
    vector<pii> arr(n);
    fori(i, 0, n) {
        cin >> arr[i].F;
        arr[i].S = i;
    }
    sorti(arr);
    int cnt = 0;
    int l=0, r=0;
    bool flag=0;
    fori(i, 0, n-1) {
        if(abs(arr[i].S-arr[i+1].S)>1) cnt++;
        else {
            if(arr[i].S>arr[i+1].S) {
                if(!flag) {
                    l = i;
                    flag=1;
                }
                r = i+1;
            }
        }
    }
    if(cnt<=2) {
        cout << "yes" << nl;
        cout << l+1 << " " << r+1 << nl;
    }
    else cout << "no" << nl;
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