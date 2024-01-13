//Author: DIVYA RAJ (aka guru_divine)
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define nl "\n"
#define pb push_back
#define popb pop_back
#define F first
#define S second
#define sz(arr) (int)arr.size()
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define mapi map<int, int>
#define un_mapi unordered_map<int, int>
#define mod 1000000007
#define fori(i,a,b) for(int i=a; i<=b; ++i)
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
        n/=2;
        a = (a*a)%mod;
    }
    return ans;
}

int combination(int n, int r, vi &fact) {
    int ans = fact[n];
    int den = (fact[r]*fact[n-r])%mod;
    ans = (ans*binPow(den, mod-2))%mod;
    return ans;
}

void solve(vi &fact) {
    int n, k; cin >> n >> k;
    vi arr;
    mapi mp;
    fori(i, 0, n-1) {
        int x; cin >> x;
        if(mp.find(x)==mp.end()) arr.pb(x);
        mp[x]++;
    }
    sortd(arr);
    int idx = 0, ans = 1;
    while(k>0) {
        int num = arr[idx];
        if(mp[num]>k) {
            //mCk
            int m = mp[num];
            ans = combination(m, k, fact);
        }
        k -= mp[num];
        idx++;
    }
    ans %= mod;
    cout << ans << nl;
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vi fact(1005);
    fact[0]=1;
    fori(i, 1, sz(fact)-1) fact[i] = (fact[i-1]*i)%mod;

    int t=1;
    cin >> t;
    while(t--) solve(fact);
    return 0;
}