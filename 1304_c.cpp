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

bool check(pii &a, pii &b, int &mini, int &maxi) {
    if(a.F<=b.F) {
        if(a.S>=b.F && a.S<=b.S) {
            mini = b.F;
            maxi = a.S;
            return true;
        }
        else if(a.S>=b.S) {
            mini = b.F;
            maxi = b.S;
            return true;
        }
    }
    else {
        if(b.S>=a.S) {
            mini = a.F;
            maxi = a.S;
            return true;
        }
        else if(b.S>=a.F && b.S<=a.S) {
            mini = a.F;
            maxi = b.S;
            return true;
        }
    }
    return false;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, pii>> arr(n+1);
    arr[0] = {0, {m, m}};
    fori(i, 1, n+1) {
        cin >> arr[i].F >> arr[i].S.F >> arr[i].S.S;
    }

    sorti(arr);

    int mini=m, maxi=m;
    fori(i, 1, n+1) {
        mini = mini - (arr[i].F - arr[i-1].F);
        maxi = maxi + (arr[i].F - arr[i-1].F);
        
        pii a = {mini, maxi};
        pii b = {arr[i].S.F, arr[i].S.S};

        if(check(a, b, mini, maxi)==false) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
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