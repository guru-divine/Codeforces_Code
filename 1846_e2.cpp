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

bool check(int num, int pow, int n, int &ans) {
    int sum=1, curNum=1;
    fori(i, 0, pow) {
        if(curNum < 1e18/num) curNum *= num;
        else return false;

        sum += curNum;
        if(sum>1e18 || sum>n) return false;
    }
    ans = sum;
    return true;
}

void solve() {
    int n; cin >> n;
    int ans;

    fori(i, 2, 70) {
        int lo=2, hi=1e9+10;
        while(lo<=hi) {
            int mid = (lo+hi)/2;
            if(check(mid, i, n, ans)) {
                if(ans==n) {
                    cout << "YES" << nl;
                    return;
                }
                lo = mid+1;
            }
            else hi = mid-1;
        }
    }

    cout << "NO" << nl;
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