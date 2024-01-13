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
    int a, b; cin >> a >> b;
    string s; cin >> s;

    if(a==0 && b==0) {
        cout << "Yes" << nl;
        return;
    }

    int n = sz(s);

    vi dx(n, 0), dy(n, 0);
    fori(i, 0, n) {
        if(s[i]=='U') dy[i] = 1;
        else if(s[i]=='D') dy[i] = -1;
        else if(s[i]=='L') dx[i] = -1;
        else dx[i] = 1;

        if(i) {
            dx[i] += dx[i-1];
            dy[i] += dy[i-1];
        }
    }

    // printS(dx);
    // printS(dy);

    int x = dx[n-1], y = dy[n-1];
    // cout << x << " " << y << nl;

    fori(i, 0, n) {
        if(x==0 && y==0) {
            if(a==dx[i] && b==dy[i]) {
                cout << "Yes" << nl;
                return;
            }
        }
        else if(x==0) {
            if(a==dx[i] && (b-dy[i])%y==0 && (b-dy[i])*y>=0) {
                cout << "Yes" << nl;
                return;
            }
        }
        else if(y==0) {
            if(b==dy[i] && (a-dx[i])%x==0 && (a-dx[i])*x>=0) {
                cout << "Yes" << nl;
                return;
            }
        }
        else if((a-dx[i])%x==0 && (b-dy[i])%y==0 && (a-dx[i])/x==(b-dy[i])/y && (a-dx[i])*x>=0) {
            cout << "Yes" << nl;
            return;
        }
    }


    cout << "No" << nl;
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