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
    int n, minDays, maxTemp; cin >> n >> minDays >> maxTemp;
    vi temp(n);
    fori(i, 0, n) {
        cin >> temp[i];
    }

    int cnt=0;
    int i=0;
    vi ans;
    while(i<n) {
        if(temp[i]<=maxTemp) {
            i++; cnt=1;
            while(i<n) {
                if(temp[i]>maxTemp) break;
                i++;
                cnt++;
            }
            if(cnt>=minDays) ans.pb(cnt);
        } else i++;
    }
    int num=0;
    fori(i, 0, sz(ans)) {
        int diff = ans[i]-minDays+1;
        num += (diff*(diff+1))/2;
    }
    cout << num << nl;
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