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
    unordered_map<int, int> ump;

    ll n; cin >> n;
    ll maxNum=0, minNum=INT_MAX;
    for(int i=0; i<n; ++i) {
        ll x; cin >> x;
        maxNum = max(maxNum, x);
        minNum = min(minNum, x);
        ump[x]++;
    }
    int maxVal = pow(maxNum, 1.5);

    vi arr;
    for(auto it: ump) {
        arr.pb(it.first);
    }
    sort(arr.begin(), arr.end());

    ll cnt=0;
    for(auto it: ump) {
        cnt += ((it.S)*(it.S-1)*(it.S-2));
    }

    for(int i=1; i<sz(arr)-1; ++i) {
        if(arr[i]>maxVal) {
            for(int j=2; j*arr[i]<=maxNum; ++j) {
                if(arr[i]%j==0) {
                    cnt += ump[arr[i]/j]*ump[arr[i]]*ump[arr[i]*j];
                }
            }
        } else {
            for(int j=2; j*j<=maxNum; ++j) {
                if(arr[i]%j==0) {
                    cnt += ump[arr[i]/j]*ump[arr[i]]*ump[arr[i]*j];
                }
            }
        }
    }

    cout << cnt << nl;
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