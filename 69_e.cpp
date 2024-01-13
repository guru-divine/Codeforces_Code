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
    vi arr(n);
    fori(i, 0, n) {
        cin >> arr[i];
    }
    // cout << nl << nl;
    mapi mp;
    set<pii> st;
    fori(i, 0, k) {
        if(mp.find(arr[i])==mp.end()) {
            mp[arr[i]]++;
            st.insert({mp[arr[i]], -arr[i]});
        }
        else {
            st.erase({mp[arr[i]], -arr[i]});
            mp[arr[i]]++;
            st.insert({mp[arr[i]], -arr[i]});
        }
    }

    if((*st.begin()).F==1) cout << -(*st.begin()).S << nl;
    else cout << "Nothing" << nl;

    fori(i, k, n) {
        if(mp.find(arr[i])==mp.end()) {
            mp[arr[i]]++;
            st.insert({mp[arr[i]], -arr[i]});
        }
        else {
            st.erase({mp[arr[i]], -arr[i]});
            mp[arr[i]]++;
            st.insert({mp[arr[i]], -arr[i]});
        }
        int x = arr[i-k];
        if(mp[x]==1) {
            st.erase({mp[x], -x});
            mp.erase(mp.find(x));
        }
        else {
            st.erase({mp[x], -x});
            mp[x]--;
            st.insert({mp[x], -x});
        }
        if((*st.begin()).F==1) cout << -(*st.begin()).S << nl;
        else cout << "Nothing" << nl;
    }
}

signed main() {
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}