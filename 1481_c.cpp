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
    int n, m; cin >> n >> m;
    vi a(n), b(n), c(m);
    un_mapi umpB;
    fori(i, 0, n) {
        cin >> a[i];
    }

    set<pii> st;
    fori(i, 0, n) {
        cin >> b[i];
        if(umpB.find(b[i])==umpB.end()) umpB[b[i]]=i+1;
        if(a[i]!=b[i]) st.insert({b[i], i+1});
    }
    fori(i, 0, m) {
        cin >> c[i];
    }
    int temp = -1;
    vi ans(m);
    ford(i, m-1, 0) {
        auto it = st.lower_bound({c[i], -1});
        if(it!=st.end() && (*it).F==c[i]) {
            ans[i] = (*it).S;
            temp = (*it).S;
            st.erase(it);
        }
        else {
            if(umpB.find(c[i])!=umpB.end()) {
                ans[i] = umpB[c[i]];
                temp = ans[i];
            }
            else ans[i] = temp;
        }
    }
    if(ans[m-1]==-1 || !st.empty()) {
        cout << "NO" << nl;
    }
    else {
        cout << "YES" << nl;
        printS(ans);
    }
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