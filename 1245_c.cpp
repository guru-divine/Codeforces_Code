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

int comb(int n, int r, vi &fact) {
    int num = fact[n];
    int den = (fact[r]*fact[n-r])%mod;
    den = binPow(den, mod-2);

    int ans = (num*den)%mod;
    return ans;
}

void fact(int n, vi &ans) {
    ans[0] = 1;
    fori(i, 1, n) {
        ans[i] = (i*ans[i-1])%mod;
    }
}

void solve(vi &factorial) {
    string s; cin >> s;
    fori(i, 0, sz(s)) {
        if(s[i]=='m' || s[i]=='w') {
            cout << "0" << nl;
            return;
        }
    }
    int ans = 1;
    int i=0;
    while(i<sz(s)) {
        if(s[i]=='n') {
            int cur = 1;
            i++;
            while(i<sz(s)) {
                if(s[i]!='n') break;
                cur++;
                i++;
            }
            int k = 1;
            int temp = 1;
            while(k<=cur/2) {
                temp = (temp+comb(cur-k, k, factorial))%mod;
                k++;
            }
            ans = (ans*temp)%mod;
        }
        else if(s[i]=='u') {
            int cur = 1;
            i++;
            while(i<sz(s)) {
                if(s[i]!='u') break;
                cur++;
                i++;
            }
            int k = 1;
            int temp = 1;
            while(k<=cur/2) {
                temp = (temp+comb(cur-k, k, factorial))%mod;
                k++;
            }
            ans = (ans*temp)%mod;
        }
        else i++;
    }

    cout << ans << nl;
}

signed main() {
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vi factorial(1e5+5);
    fact(sz(factorial), factorial);

    solve(factorial);
    return 0;
}