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
    int n; cin >> n;
    if(n==1) {
        cout << "a" << nl;
        return;
    }
    int num = -1;
    for(int i=2; i<=n; ++i) {
        if(n%i!=0) {
            num = i;
            break;
        }
    }

    if(num==-1) {
        string ans="";
        string temp="ab";
        for(int i=2; i<=n; i+=2) {
            ans += temp;
        }
        if(n%2==1) ans += "a";
        cout << ans << nl;
    }
    else {
        string ans = "";
        string temp = "abcdefghijklmnopqrstuvwxyz";
        string tempi = temp.substr(0, num);

        for(int i=num; i<=n; i+=num) {
            ans += tempi;
        }
        ans += tempi.substr(0, n%num);
        cout << ans << nl;
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