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

bool check(int &mid, int &h, int &c, int &t) {
    double cur = (double)(mid*(h+c) + h)/(2*mid+1);
    if(cur>t*1.0) return true;
    return false;
}

void solve() {
    int h, c, t; cin >> h >> c >> t;
    double mid = (c+h)/2.0;
    if(h==t) {
        cout << "1" << nl;
        return;
    }
    if(mid > t*1.0 || c+h==2*t) {
        cout << "2" << nl;
        return;
    }

    int lo = 0, hi = 1e9;
    int ans = -1;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        if(check(mid, h, c, t)) {
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }

    long double ans1 = (long double)(ans*(h+c)+h)/(2*ans+1);
    long double ans2 = (long double)((ans+1)*(h+c)+h)/(2*(ans+1)+1);

    ans1 = abs(ans1-t);
    ans2 = abs(ans2-t);

    if(ans1<=ans2) cout << 2*ans+1 << nl;
    else cout << 2*(ans+1)+1 << nl;
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