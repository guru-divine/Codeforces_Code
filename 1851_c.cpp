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
    vi arr(n);
    fori(i, 0, n) {
        cin >> arr[i];
    }
    if(arr[0]==arr[n-1]) {
        int ans=0;
        fori(i, 0, n) {
            if(arr[i]==arr[0]) ans++;
            if(ans>=k) {
                cout << "YES" << nl;
                return;
            }
        }
        cout << "NO" << nl;
    }
    else {
        int lIdx=-1, rIdx=-1;
        int cnt=0;
        fori(i, 0, n) {
            if(arr[i]==arr[0]) cnt++;
            if(cnt==k) {
                lIdx = i;
                break;
            }
        }
        cnt=0;
        ford(i, n-1, 0) {
            if(arr[i]==arr[n-1]) cnt++;
            if(cnt==k) {
                rIdx = i;
                break;
            }
        }

        if(min(lIdx, rIdx)!=-1 && rIdx>lIdx) cout << "YES" << nl;
        else cout << "NO" << nl;
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