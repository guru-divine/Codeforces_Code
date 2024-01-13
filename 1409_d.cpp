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

int findSum(int num) {
    int ans = 0;
    while(num) {
        ans += num%10;
        num /= 10;
    }

    return ans;
}

void solve() {
    int n, s; cin >> n >> s;

    if(findSum(n)<=s) {
        cout << "0" << nl;
        return;
    }

    int ans=0, pow = 1;
    fori(i, 0, 18) {
        int dig = (n/pow)%10;
        n += ((10-dig)%10)*pow;
        ans += ((10-dig)%10)*pow;

        if(findSum(n)<=s) break;
        pow *= 10;
    }

    cout << ans << nl;
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