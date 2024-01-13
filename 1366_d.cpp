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
    vector<bool> isPrime(1e7+5, 1);
    map<int, pii> mp;
    vi prime;
    isPrime[1]=0;
    fori(i, 2, 1e7+5) {
        if(isPrime[i]) {
            prime.pb(i);
            for(int j=i*i; j<1e7+5; j+=i) {
                isPrime[j]=0;
            }
        }
    }

    int n; cin >> n;
    vi arr(n), brr(n);
    fori(i, 0, n) {
        int x; cin >> x;
        int dupX = x;
        if(mp.find(dupX)!=mp.end()) {
            arr[i] = mp[dupX].F;
            brr[i] = mp[dupX].S;
            continue;
        }
        if(isPrime[x]) {
            arr[i]=-1; brr[i]=-1;
            continue;
        }

        int num1=1, num2=1;
        fori(j, 2, n+1) {
            if(isPrime[j] && x%j==0) {
                while(x%j==0) {
                    num1 *= j;
                    x /= j;
                }
                num2 = x;
                break;
            }
        }

        if(num2==1) {
            mp[dupX] = {-1, -1};
            arr[i]=-1; brr[i]=-1;
        }
        else {
            mp[dupX] = {num1, num2};
            arr[i]=num1; brr[i]=num2;
        }
    }

    printS(arr);
    printS(brr);
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