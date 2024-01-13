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
    vector<vector<char>> mat(3, vector<char>(3));
    fori(i, 0, 3) {
        fori(j, 0, 3) {
            cin >> mat[i][j];
        }
    }

    fori(i, 0, 3) {
        if(mat[i][0]==mat[i][1] && mat[i][1]==mat[i][2] && mat[i][0]!='.') {
            cout << mat[i][0] << nl;
            return;
        }
        if(mat[0][i]==mat[1][i] && mat[1][i]==mat[2][i] && mat[0][i]!='.') {
            cout << mat[0][i] << nl;
            return;
        }
    }
    if(mat[0][0]==mat[1][1] && mat[1][1]==mat[2][2] && mat[0][0]!='.') {
        cout << mat[0][0] << nl;
        return;
    }
    if(mat[2][0]==mat[1][1] && mat[1][1]==mat[0][2] && mat[2][0]!='.') {
        cout << mat[2][0] << nl;
        return;
    }

    cout << "DRAW" << nl;
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