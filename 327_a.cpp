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
    int cnt=0;
    vi arr(n);
    fori(i, 0, n) {
        int x; cin >> x;
        if(!x) arr[i]=1;
        else {
            arr[i]=-1;
            cnt++;
        }
    }
    if(cnt==n) {
        cout << n-1 << nl;
        return;
    }

    int ans = 0, temp=0;
    int l=-1, lo=-1, r=n+1;
    fori(i, 0, n) {
        if(temp<=0) {
            temp = 0;
            l = i;
        }
        temp += arr[i];
        if(temp>ans) {
            ans = temp;
            lo = l;
            r = i;
        }
    }
    ans=0;
    fori(i, 0, n) {
        if(i>=lo && i<=r) {
            if(arr[i]==1) ans++;
        }
        else {
            if(arr[i]==-1) ans++;
        }
    }
    // cout << lo << " " << r << nl;
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