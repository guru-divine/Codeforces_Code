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

    vi isPrime(1e4, 1);
    isPrime[1]=0;
    fori(i, 2, 1e4) {
        if(isPrime[i]) {
            for(int j=i*i; j<1e4; j+=i) {
                isPrime[j]=0;
            }
        }
    }
    int n; cin >> n;
    vi arr;
    int num = 2;
    while(num<=n) {
        arr.pb(num);
        num *= 2;
    }
    fori(i, 3, n+1) {
        if(isPrime[i]) {
            for(int j=i; j<=n; j*=i) arr.pb(j);
        }
    }


    cout << arr.size() << nl;
    printS(arr);
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