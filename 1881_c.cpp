//Author: DIVYA RAJ (aka guru_divine)
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define nl "\n"
#define pb push_back
#define popb pop_back
#define F first
#define S second
#define sz(arr) (int)arr.size()
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define mapi map<int, int>
#define un_mapi unordered_map<int, int>
#define mod 1000000007
#define fori(i,a,b) for(int i=a; i<=b; ++i)
#define ford(i,a,b) for(int i=a; i>=b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reversei(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()-1) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()-1) {cout << arr[i] << nl;}
using namespace std; 

void solve() {
    int n; cin >> n;
    vector<vi> mat(n, vi(n));
    fori(i, 0, n-1) {
        fori(j, 0, n-1) {
            char x; cin >> x;
            mat[i][j] = x-'a';
        }
    }
    int ans = 0;
    fori(i, 0, n-1) {
        fori(j, 0, n-1) {
            int maxi = max({mat[i][j], mat[n-i-1][n-j-1], mat[j][n-i-1], mat[n-j-1][i]});
            int sum = mat[i][j] + mat[j][n-i-1] + mat[n-i-1][n-j-1] + mat[n-j-1][i];
            ans += 4*maxi-sum;
        }
    }
    ans/=4;
    cout << ans << nl;
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}