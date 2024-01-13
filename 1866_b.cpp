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
#define mod 998244353
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
        if(n&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        n >>= 1;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    un_mapi a, b;
    vi arr(n);
    fori(i, 0, n) {
        cin >> arr[i];
    }
    fori(i, 0, n) {
        int freq; cin >> freq;
        a[arr[i]] = freq;
    }

    bool flag=0;
    int ans = 1;

    int m; cin >> m;
    vi brr(m);
    fori(i, 0, m) cin >> brr[i];
    fori(i, 0, m) {
        int freq; cin >> freq;
        b[brr[i]] = freq;
        if(a.find(brr[i]) == a.end()) flag=1;
        else if(a[brr[i]]<b[brr[i]]) flag=1;
        else {
            if(a[brr[i]]!=b[brr[i]]) ans = (ans*2)%mod;
            a.erase(a.find(brr[i]));
        }
    }
    if(flag) ans = 0;
    else {
        ans = (ans*binPow(2, sz(a)))%mod;
    }

    cout << ans << nl;
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