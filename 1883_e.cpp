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

void solve(vi &twoPow) {
    int n; cin >> n;
    vi arr(n);
    fori(i, 0, n-1) cin >> arr[i];
    vi tingting(n);
    fori(i, 1, n-1) {
        if(arr[i]>=arr[i-1]) {
            auto it = lower_bound(all(twoPow), arr[i]/arr[i-1]);
            int diff = it - twoPow.begin();
            if(*it * arr[i-1]>arr[i]) diff--;
            tingting[i] = diff;
        }
        else {
            auto it = lower_bound(all(twoPow), arr[i-1]/arr[i]);
            int diff = it - twoPow.begin();
            if(*it * arr[i]<arr[i-1]) diff++;
            tingting[i] = -diff;
        }
    }
    // fori(i, 0, n-1) cout << tingting[i].F << " ";
    // cout << nl;
    vi inc_power(n, 0);
    fori(i, 1, n-1) {
        if(inc_power[i-1]>tingting[i]) inc_power[i] = inc_power[i-1]-tingting[i];
    }
    // printS(inc_power);
    int sum = 0;
    fori(i, 0, n-1) sum += inc_power[i];
    cout << sum << nl;
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vi twoPow;
    int num = 1;
    fori(i, 0, 32) {
        twoPow.pb(num);
        num *= 2;
    }
    int t=1;
    cin >> t;
    while(t--) solve(twoPow);
    return 0;
}