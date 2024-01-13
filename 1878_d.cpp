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
    int n, k; cin >> n >> k;
    vi l(k), r(k), pref(n+1, 0);

    string s; cin >> s;

    fori(i, 0, k) cin >> l[i];
    fori(i, 0, k) cin >> r[i];
    string t;
    fori(i, 0, k) {
        string temp = s.substr(l[i]-1, r[i]-l[i]+1);
        reversei(temp);
        t += temp;
    }
    // cout << t << nl;

    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        auto idx = upper_bound(all(l), x) - l.begin();
        idx--;
        int a = min(x, l[idx]+r[idx]-x);
        int b = max(x, l[idx]+r[idx]-x);
        // cout << a << "," << b << " ";
        // a++, b++;
        pref[b]++;
        pref[a-1]--;
    }
    string ans;
    ford(i, n, 0) {
        if(i<n) pref[i] += pref[i+1];
    }
    // printS(pref);
    fori(i, 1, n+1) {
        if(pref[i]%2==1) ans += t[i-1];
        else ans += s[i-1];
    }

    cout << ans << nl;
}

signed main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}