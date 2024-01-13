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

void solve(vi &onlyPrime) {
    int n; cin >> n;
    vi arr(n);
    // un_mapi mp;

    fori(i, 0, n) cin >> arr[i];
    vi vis(4*1e4+5, 0);

    fori(i, 0, n) {
        fori(j, 0, sz(onlyPrime)) {
            if(arr[i]%onlyPrime[j]==0) {
                vis[onlyPrime[j]]++;
                if(vis[onlyPrime[j]]>1) {
                    cout << "YES" << nl;
                    return;
                }
                while(arr[i]%onlyPrime[j]==0) {
                    arr[i]/=onlyPrime[j];
                }
            }
            if(arr[i]==1) break;
        }
        if(arr[i]!=1 && arr[i]<4*1e4+5) {
            if(vis[arr[i]]) {
                cout << "YES" << nl;
                return;
            }
        }
    }
    sorti(arr);
    fori(i, 1, n) {
        if(arr[i]==arr[i-1] && arr[i]!=1) {
            cout << "YES" << nl;
            return;
        }
    }

    cout << "NO" << nl;
}

signed main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vi onlyPrime;

    vector<bool> isPrime(4*1e4+5, 1);
    isPrime[0]=isPrime[1]=0;
    fori(i, 2, sz(isPrime)) {
        if(isPrime[i]) {
            onlyPrime.pb(i);
            for(int j=i*i; j<sz(isPrime); j+=i) {
                isPrime[j]=0;
            }
        }
    }

    int t; cin >> t;
    while(t--) solve(onlyPrime);
    return 0;
}