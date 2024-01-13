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
    vi arr(n);
    vi ans(n), prefPar(n, 0);
    fori(i, 0, n-1) {
        cin >> arr[i];
        ans[i] = arr[i];
        prefPar[i] = arr[i]%2;
        if(i) {
            ans[i] += ans[i-1];
            prefPar[i] += prefPar[i-1];
        }
    }
    fori(i, 0, n-1) {
        if(prefPar[i]==0 || prefPar[i]==2) {}
        else if(prefPar[i]==1) {
            if(!i) {}
            else ans[i]--;
        }
        else {
            int minus = prefPar[i]/3 + (prefPar[i]%3==1);
            ans[i] -= minus;
        }
    }
    printS(ans);
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