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
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std; 

void solve() {
    int n; cin >> n;
    vector<bool> arr(n);
    fori(i, 0, n-1) {
        bool x; cin >> x;
        arr[i] = x;
    }

    vi sides_polygnon;
    for(int i=3; i<=n; ++i) {
        if(n%i==0) sides_polygnon.pb(i);
    }
    for(int i=0; i<sz(sides_polygnon); ++i) {
        int sides = sides_polygnon[i];
        for(int j=0; j<(n/sides); ++j) {
            bool isPossible = 1;
            for(int k=j; k<n; k+=(n/sides)) isPossible*=arr[k];
            if(isPossible) {
                cout << "YES" << nl; return;
            }
        }
    }
    cout << "NO" << nl;
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