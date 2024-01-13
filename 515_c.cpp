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
    vi arr[10];
    arr[2] = {2};
    arr[3] = {3};
    arr[4] = {2, 2, 3};
    arr[5] = {5};
    arr[6] = {3, 5};
    arr[7] = {7};
    arr[8] = {2, 2, 2, 7};
    arr[9] = {2, 3, 3, 7};

    int n; cin >> n;
    string num; cin >> num;
    vi ans;
    fori(i, 0, n) {
        int dig = num[i]-'0';
        if(dig>1) {
            fori(j, 0, arr[dig].size()) ans.pb(arr[dig][j]);
        }
    }
    sortd(ans);

    string s;
    fori(i, 0, sz(ans)) {
        s += (ans[i] + '0');
    }
    // printS(ans);

    cout << s << nl;
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