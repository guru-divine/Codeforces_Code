//Author: DIVYA RAJ (aka guru_divine)
#include <bits/stdc++.h>
#define ll long long
#define int unsigned long long
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

void solve() {
    int n; cin >> n;
    int val = 0;
    vi A(n), B(n);
    fori(i, 0, n-1) {
        cin >> A[i] >> B[i];
        val = __gcd(val, A[i]*B[i]);
    }
    if(val==1) {
        cout << "-1" << nl;
        return;
    }

    for(int i=2; i<5e4+5; ++i) {
        if(val%i==0) {
            cout << i << nl;
            return;
        }
    }
    for(int i=0; i<n; ++i) {
        if(val%A[i]==0) {
            cout << A[i] << nl;
            return;
        }
        else if(val%B[i]==0) {
            cout << B[i] << nl;
            return;
        }
    }
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}