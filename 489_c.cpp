//Author: DIVYA RAJ
#include <bits/stdc++.h>
#define ll long long
// #define int long long
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
    int m, s; cin >> m >> s;
    // string small;
    string smallestNum="", largestNum="";
    int dupS = s;

    int x;
    if(m==1 && s==0) {
        cout << "0 0" << nl;
        return;
    }
    if(s==0 || s>9*m) {
        cout << "-1 -1" << nl;
        return;
    }
    fori(i, 0, m) {
        x = m-i-1;
        // smallestNum *= 10;
        if(9*x >= s) {
            if(!i) {
                smallestNum += to_string(1);
                s -= 1;
            } else {
                // cout << "0";
                smallestNum += to_string(0);
            }
        } else {
            smallestNum += to_string(s-9*x);
            s -= (s-9*x);
        }
    }
    // cout << smallestNum << nl;
    s = dupS;

    fori(i, 0, m) {
        // largestNum *= 10;
        if(!s) largestNum += to_string(0);
        else if(s>9) {
            largestNum += to_string(9);
            s -= 9;
        }
        else {
            largestNum += to_string(s);
            s = 0;
        }
    }
    cout << smallestNum << " " << largestNum << nl;
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