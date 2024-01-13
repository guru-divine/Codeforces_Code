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

bool cmp(vi &a, vi &b, int idx, int &parIdx) {
    int cnt=0;
    fori(i, 0, 5) {
        if(a[i]<b[i]) cnt++;
    }
    if(cnt<3) {
        a = b;
        parIdx = idx;
        return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<vi> rank(n, vi(5));

    fori(i, 0, n) {
        fori(j, 0, 5) {
            cin >> rank[i][j];
        }
    }

    vi par = rank[0];
    int parIdx = 0;
    fori(i, 1, n) {
        cmp(par, rank[i], i, parIdx);
    }

    fori(i, 0, n) {
        if(i==parIdx) continue;

        if(cmp(par, rank[i], i, parIdx)==false) {
            cout << "-1" << nl;
            return;
        }
    }
    cout << parIdx+1 << nl;
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