//Author: DIVYA RAJ
#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define pb push_back
#define popb pop_back
#define F first
#define S second
#define sz(arr) arr.size()
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mapi map<int, int>
#define un_mapi unordered_map<int, int>
#define mod 1000000007
#define fori(i,a,b) for(int i=a; i<b; ++i)
#define forll(i,a,b) for(ll i=a; i<b; ++i)
#define ford(i,a,b) for(int i=a; i<b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

ll binPow(ll a, ll n) {
    ll ans = 1;
    while(n) {
        if(n&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        n >>= 1;
    }
    return ans;
}

void fact(ll n, vll &ans) {
    ans[0] = 1;
    forll(i, 0, n) {
        ans[i] = (i*ans[i-1])%mod;
    }
}

ll comb(ll n, ll r, vll &fact) {
    ll num = fact[n];
    ll den = (fact[r]*fact[n-r])%mod;
    den = binPow(den, mod-2);

    ll ans = (num*den)%mod;
    return ans;
}

void solve(vll &factorial) {
    int n; cin >> n;
    vll a, b;

    forll(i, 0, n) {
        int x; cin >> x;
        // a.insert(x); 
        a.pb(x);
    }
    forll(i, 0, n) {
        int x; cin >> x;
        // b.insert(x); 
        b.pb(x);
    }
    sorti(a);
    sorti(b);

    forll(i, 0, n) {
        if(a[i]<=b[i]) {
            cout << "0" << nl;
            return;
        }
    }

    ll ans=1;
    for(ll i=n-1; i>=0; --i) {
        ll num = (a.end()-upper_bound(a.begin(), a.end(), b[i])) - ((n-1)-i);
        ans = (ans*num)%mod;
    }

    ll den=1, flag=0, cnt=0;
    forll(i, 0, n-1) {
        if(!flag) {
            if(a[i]==a[i+1]) {
                cnt=2;
                flag=1;
            }
        }
        else {
            if(a[i]!=a[i+1]) {
                flag=0;
                den = (den*factorial[cnt])%mod;
                cnt=0;
            }
            else cnt++;
        }
    }

    den = binPow(den, mod-2);

    ans = (ans*den)%mod;

    cout << ans << nl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vll factorial(200005);
    fact(200005, factorial);

    int t; cin >> t;
    while(t--) solve(factorial);
    return 0;
}