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

bool func(int a, int b) {
    int cnt=0;
    while(a!=b) {
        int c = abs(a-b);
        a = b;
        b = c;
        cnt++;
    }
    return (cnt%2);
}

void solve() {
    int n; cin >> n;
    vi arr(n), brr(n);
    fori(i, 0, n) {
        cin >> arr[i];
    }
    fori(i, 0, n) {
        cin >> brr[i];
    }
    vi ans(n, -1);
    fori(i, 0, n) {
        if(arr[i]==0) {
            if(brr[i]!=0) ans[i]=0;
        }
        else {
           ans[i] = func(arr[i], brr[i]); 
        }
    }

    sorti(ans);
    fori(i, 0, n) {
        if(ans[i]!=-1) {
            if(ans[i]==ans[n-1]) {
                cout << "YES" << nl;
                return;
            }
            else {
                cout << "NO" << nl;
                return;
            }
        }
    }
    cout << "YES" << nl;
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