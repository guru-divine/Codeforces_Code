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
    vi charPos[52];
    fori(i, 0, n) {
        if(s[i]-'a'>=0) {
            charPos[s[i]-'a'+26].pb(i);
        }
        else {
            charPos[s[i]-'A'].pb(i);
        }
    }

    // fori(i, 0, 52) {
    //     if(!charPos[i].empty()) {
    //         cout << i << "->";
    //         fori(j, 0, sz(charPos[i])) {
    //             cout << charPos[i][j] << " ";
    //         }
    //         cout << nl;
    //     }
    // }

    int minAns = INT_MAX;
    fori(i, 0, n) {
        int curMax = INT_MIN;
        bool flag=0;
        fori(j, 0, 52) {
            if(!charPos[j].empty()) {
                auto it = lower_bound(all(charPos[j]), i);
                if(it==charPos[j].end()) {
                    flag=1;
                    break;
                }
                else curMax = max(curMax, *it - i + 1);
            }
        }
        if(!flag) {
            minAns = min(minAns, curMax);
        }
    }

    cout << minAns << nl;
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