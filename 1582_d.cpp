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
    vi arr(n), ans(n);
    fori(i, 0, n-1) cin >> arr[i];
    int idx = 0;
    // make triplet of (0, 1, 2nd element) of sum zero
    if(n%2==1) {
        if(arr[0]+arr[1]!=0) {
            ans[0] = ans[1] = arr[2];
            ans[2] = -(arr[0]+arr[1]);
        }
        else if(arr[1]+arr[2]!=0) {
            ans[1] = ans[2] = arr[0];
            ans[0] = -(arr[1]+arr[2]);
        }
        else {
            ans[2] = ans[0] = arr[1];
            ans[1] = -(arr[2]+arr[0]);
        }
        idx = 3;
    }
    while(idx<n) {
        ans[idx] = -arr[idx+1], ans[idx+1] = arr[idx];
        idx+=2;
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