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
    un_mapi ump, par, child;
    int n; cin >> n;
    vi arr(n);

    fori(i, 0, n) {
        cin >> arr[i];
        par[arr[i]] = arr[i];
        child[arr[i]] = 1;
        ump[arr[i]]++;
    }

    sorti(arr);

    fori(i, 0, n) {
        if(ump[2*arr[i]]) {
            par[2*arr[i]] = arr[i];
            child[arr[i]]++;
        }
        else if(arr[i]%3==0 && ump[arr[i]/3]) {
            par[arr[i]/3] = arr[i];
            child[arr[i]]++;
        }
    }

    // for(auto it: par) {
    //     cout << it.S << "->" << it.F << nl;
    // }

    int lowest;
    for(auto it: child) {
        if(it.S==1) lowest = it.F;
    }

    vi ans;
    while(par[lowest]!=lowest) {
        ans.pb(lowest);
        lowest = par[lowest];
    }
    ans.pb(lowest);

    reversei(ans);
    printS(ans);
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