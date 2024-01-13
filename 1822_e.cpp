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
    string s; cin >> s;
    if(s.size()%2==1) {
        cout << "-1" << nl;
        return;
    }

    vi alphCnt(26, 0);

    vi cnt(26, 0);
    int totCnt=0;
    fori(i, 0, n) {
        alphCnt[s[i]-'a']++;
    }
    sortd(alphCnt);

    fori(i, 0, n/2) {
        if(s[i]==s[n-i-1]) {
            cnt[s[i]-'a']++;
            totCnt++;
        }
    }

    sortd(cnt);

    if(alphCnt[0]>n/2) {
        cout << "-1" << nl;
        return;
    }
    if(2*cnt[0]<=totCnt) {
        cout << (totCnt+1)/2 << nl;
    }
    else {
        cout << cnt[0] << nl;
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