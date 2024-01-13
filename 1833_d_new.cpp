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
    vi arr(n), ans;
    int idx=-1;
    fori(i, 0, n) {
        cin >> arr[i];
        if(arr[i]==n) {
            idx=i;
        }
    }
    if(n==1) {
        cout << "1" << nl;
        return;
    }
    if(idx==0) {
        fori(i, 0, n) {
            if(arr[i]==n-1) {
                idx=i;
                break;
            }
        }
    }
    if(idx>0) {
        fori(i, idx, n) ans.pb(arr[i]);
        if(idx!=n-1) ans.pb(arr[idx-1]);
        ford(i, idx-1-(idx!=n-1), 0) {
            if(arr[0]>arr[i]) {
                // if(idx!=n-1 && i==idx-1) ans.pb(arr[i]);
                break;
            }
            else ans.pb(arr[i]);
        }
        int num = ans.back();
        int i=0;
        while(arr[i]!=num) {
            ans.pb(arr[i]);
            i++;
        }
    }

    printS(ans);
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