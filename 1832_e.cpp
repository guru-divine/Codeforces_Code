//Author: DIVYA RAJ
#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define pb push_back
#define popb pop_back
#define F first
#define S second
#define sz(arr) arr.size()
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mapi map<int, int>
#define un_mapi unordered_map<int, int>
#define mod 998244353
#define fori(i,a,b) for(int i=a; i<b; ++i)
#define forll(i,a,b) for(ll i=a; i<b; ++i)
#define ford(i,a,b) for(int i=a; i<b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

void solve() {
    ll n, a, x, y, m, k;
    cin >> n >> a >> x >> y >> m >> k;

    vll arr(n+1);
    arr[0]=0;
    arr[1]=a;
    forll(i, 2, n+1) {
        arr[i]=((arr[i-1]*x)%m + y)%m;
    }
    printS(arr);

    vll prefSum(n+1);
    forll(i, 0, n+1) {
        prefSum[i]=arr[i];
        if(i) prefSum[i] = (prefSum[i] + prefSum[i-1]);
    }
    printS(prefSum);

    vector<vll> b(n+1, vll(k+1));

    //base condition
    forll(i, 0, n+1) {
        if(i<=k) b[0][i]=0;
        b[i][0]=prefSum[i];
    }

    //dp
    forll(i, 1, n+1) {
        forll(j, 1, k+1) {
            b[i][j] = (b[i-1][j] + b[i-1][j-1]);
        }
    }

    forll(i, 0, n+1) {
        forll(j, 0, k+1) {
            cout << b[i][j] << " ";
        }
        cout << nl;
    }

    ll ans=0;
    forll(i, 1, n+1) {
        // ans ^= (b[i][k]*i);
        ans ^= (arr[i]*i);
    }

    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}