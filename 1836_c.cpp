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
        if(n&1) ans = (ans*a);
        a = (a*a);
        n >>= 1;
    }
    return ans;
}

void solve() {
    int a, b, c, k; cin >> a >> b >> c >> k;

    int loA = binPow(10, a-1), hiA = binPow(10, a);
    int loB = binPow(10, b-1), hiB = binPow(10, b);
    int loC = binPow(10, c-1), hiC = binPow(10, c);

    int curr=0, x, y;
    fori(i, loA, hiA) {
        int l = max(loC-i, loB);
        int r = min(hiC-i, hiB)-1;

        if(r>=l){

            if(curr<k && (curr+r-l+1)>=k){    
                x = i;
                y = l+k-curr-1;
                cout << x << " + " << y << " = " << x+y <<nl;
                return;
            }
            curr += (r-l+1);
        }
    }

    cout << "-1" << nl;

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