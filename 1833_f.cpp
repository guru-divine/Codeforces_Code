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
        if(n&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        n >>= 1;
    }
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    un_mapi ump;
    vi arr;

    fori(i, 0, n) {
        int x; cin >> x;
        ump[x]++;
    }
    if(m==1) {
        int ans=0;
        for(auto it: ump) ans += it.S;
        cout << ans << nl;
        return;
    }

    for(auto it: ump) {
        arr.pb(it.F);
    }
    sorti(arr);

    int ans = 0;
    int cnt=1;
    int temp=ump[arr[0]];
    for(int i=1; i<sz(arr); ++i) {
        if(arr[i]!=arr[i-1]+1) {
            cnt=1;
            temp=ump[arr[i]];
        }
        else {
            cnt++; temp = (temp*ump[arr[i]])%mod;
            if(cnt>m) {
                temp = (temp*binPow(ump[arr[i]-m], mod-2))%mod;
            }
            if(cnt>=m) {
                ans = (ans+temp)%mod;
            }
        }
    }

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