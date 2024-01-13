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

void multiply(int a[][4], int b[][4]) {
    int ans[4][4];
    fori(i, 0, 4) {
        fori(j, 0, 4) {
            ans[i][j]=0;
            fori(k, 0, 4) {
                ans[i][j] = (ans[i][j] + a[i][k]*b[k][j])%mod;
            }
        }
    }

    fori(i, 0, 4) {
        fori(j, 0, 4) {
            a[i][j] = ans[i][j];
        }
    }
}

int power(int f[][4], int mul[][4], int n) {
    if(n==1) return f[3][3];

    power(f, mul, n/2);
    multiply(f, f);

    if(n%2!=0) multiply(f, mul);

    return f[3][3];
}

int findD(int n, int mul[][4], int f[][4]) {
    if(n==0) return 1;
    if(n==1) return 0;

    return power(f, mul, n);
}

void solve() {
    int n; cin >> n;
    int mul[4][4] = {{0,1,1,1},
                     {1,0,1,1},
                     {1,1,0,1},
                     {1,1,1,0}};
    
    int f[4][4];
    fori(i, 0, 4) {
        fori(j, 0, 4) {
            f[i][j]=mul[i][j];
        }
    }

    cout << findD(n, mul, f) << nl;
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
