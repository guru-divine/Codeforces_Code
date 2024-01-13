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
    int w, f; cin >> w >> f;
    int n; cin >> n;
    int sum = 0;
    vi arr(n);
    fori(i, 0, n) {
        cin >> arr[i];
        sum += arr[i];
    }
    if(w<f) swap(w, f);
    
    if(w>=sum) {
        cout << "1" << nl;
        return;
    }

    vector<bool> memo(sum+1, 0);
    memo[0]=1;
    fori(i, 0, n) {
        ford(j, sum, 0) {
            if(j-arr[i]>=0) memo[j] = memo[j] || memo[j-arr[i]]; 
        }
    }

    int lo = 1, hi = (sum+w-1)/w;
    int ans = (sum+w-1)/w;
    
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        int target = mid*w;

        int sum1 = 0;
        ford(i, target, 0) {
            if(memo[i]==1) {
                sum1 = i;
                break;
            }
        }
        if(f*mid >= sum-sum1) {
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }

    cout << ans << nl;

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