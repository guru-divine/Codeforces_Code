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
#define printS(arr) fori(i,0,arr.size()-1) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()-1) {cout << arr[i] << nl;}
using namespace std; 

void solve(vi &primes) {
    int a, b, k; cin >> a >> b >> k;
    int minMov;
    if(a==b) minMov = 0;
    else if(__gcd(a, b)==a || __gcd(a, b)==b) minMov = 1;
    else minMov = 2;

    int cntA = 0, cntB = 0;
    for(auto u: primes) {
        if(u*u>a) break;
        while(a%u==0) {
            a/=u;
            cntA++;
        }
    }
    if(a>1) cntA++;
    for(auto u: primes) {
        if(u*u>b) break;
        while(b%u==0) {
            b/=u;
            cntB++;
        }
    }
    if(b>1) cntB++;
    if(minMov<=k && k<=(cntA+cntB) && ((k==1 && minMov==1) || k!=1)) cout << "YES" << nl;
    else cout << "NO" << nl;
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<bool> isPrime(1e5, 1);
    vi primes;
    for(int i=2; i<1e5; ++i) {
        if(isPrime[i]) {
            primes.pb(i);
            for(int j=i*i; j<1e5; j+=i) {
                isPrime[j] = 0;
            }
        }
    }

    int t=1;
    cin >> t;
    while(t--) solve(primes);
    return 0;
}