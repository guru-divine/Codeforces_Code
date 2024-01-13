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

void solve(vi &primes) {
    int n; cin >> n;
    map<int, vi> mp;
    vi color(n);

    fori(i, 0, n) {
        int x; cin >> x;
        mp[x].pb(i);
    }
    int k=1;
    fori(i, 0, sz(primes)) {
        bool flag=0;
        for(int j=primes[i]; j<=1000; j+=primes[i]) {
            if(mp.find(j)!=mp.end()) {
                for(auto it: mp[j]) {
                    color[it] = k;
                    flag=1;
                }
                // k++;
                mp.erase(mp.find(j));
            }
        }
        if(flag) k++;
    }
    cout << k-1 << nl;
    printS(color);
}

signed main() {
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vi isPrime(1e3+5, 1);
    vi primes;
    fori(i, 2, sz(isPrime)) {
        if(isPrime[i]) {
            primes.pb(i);
            for(int j=i*i; j<sz(isPrime); j+=i) {
                isPrime[j]=0;
            }
        }
    }

    int t; cin >> t;
    while(t--) solve(primes);
    return 0;
}