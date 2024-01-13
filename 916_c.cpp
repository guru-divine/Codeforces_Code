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
    int n, m; cin >> n >> m;
    int num = *lower_bound(all(primes), n-1);

    int first = num - (n-2);
    cout << num << " " << num << nl;
    fori(i, 1, n) {
        if(i==1) cout << i << " " << i+1 << " " << first << nl;
        else cout << i << " " << i+1 << " 1" << nl;
    }

    int isLeft = m - (n-1);
    if(isLeft>0) {
        fori(i, 1, n+1) {
            fori(j, i+2, n+1) {
                cout << i << " " << j << " 10000000" << nl;
                isLeft--;
                if(isLeft==0) return;
            }
        }
    }
}

signed main() {
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vi isPrime(1e6, 1);
    vi primes;
    fori(i, 2, sz(isPrime)) {
        if(isPrime[i]) {
            primes.pb(i);
            for(int j=i*i; j<sz(isPrime); j+=i) {
                isPrime[j]=0;
            }
        }
        
    }
    solve(primes);
    return 0;
}