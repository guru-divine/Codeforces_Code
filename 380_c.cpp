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
    string s; cin >> s;
    int n = s.size();
    vi cnt(n, 0);
    stack<pair<char, int>> st;vi open, close;

    fori(i, 0, n) {
        if(st.empty()) st.push({s[i], i});
        else {
            if(st.top().F=='(' && s[i]==')') {
                if(i<n-1) cnt[i+1]+=2;
                open.pb(st.top().S);
                close.pb(i);
                st.pop();
            }
            else st.push({s[i], i});
        }
    }
    fori(i, 1, n) {
        cnt[i] += cnt[i-1];
    }

    // printS(open); printS(close);
    sorti(open);
    sorti(close);
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        int openi_l = lower_bound(all(open), l) - open.begin();
        int openi_r = lower_bound(all(open), r) - open.begin();
        if(openi_l==openi_r && lower_bound(all(open), r)!=open.end() && r==*lower_bound(all(open), r)) openi_r++;
        int openi = openi_r - openi_l;


        int closei_l = lower_bound(all(close), openi_l) - close.begin();
        int closei_r = lower_bound(all(close), r) - close.begin();
        if(closei_l==closei_r && lower_bound(all(close), r)!=close.end() && r==*lower_bound(all(close), r)) closei_r++;
        int closei = closei_r - closei_l;
        // int closei = lower_bound(all(close), r) - lower_bound(all(close), max(closei_l, l));
        // cout << openi << " " << closi << nl;
        cout << min(closei, openi)*2 << nl;
    }
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