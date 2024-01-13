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

vi pref(40004, 0);

void modDif(int a, int b) {
    fori(i, 0, a*b) {
        pref[i] = ((i%a)%b != (i%b)%a);
        if(i) pref[i] += pref[i-1];
    }
}

int cntProb(int a, int b, int r) {
    int ans = (r/(a*b))*pref[a*b-1] + pref[r%(a*b)];
    return ans;
}

void solve() {
    int a, b, q; cin >> a >> b >> q;
    if(b<a) swap(a, b);
    modDif(a, b);
    while(q--) {
        int l, r; cin >> l >> r;
        int ans = cntProb(a, b, r) - cntProb(a, b, l-1);
        // cout << nl;
        cout << ans << " ";
    }
    cout << nl;
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}