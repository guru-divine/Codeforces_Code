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
#define mod 1000000007
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
    int n, k; cin >> n >> k;
    vll arr(n), prefSum(n);
    ll totSum=0;
    fori(i, 0, n) {
        cin >> arr[i];
        // totSum += arr[i];
    }
    sorti(arr);

    fori(i, 0, n) {
        prefSum[i] = arr[i];
        if(i) prefSum[i] += prefSum[i-1];
    }

    ll ans=0;

    for(int a=0; a<=k; ++a) {
        int b=k-a;
        int l=2*a;
        int r=n-b;

        ll num1 = (l==0) ? 0 : prefSum[l-1];
        ll num2 = (r==n) ? 0 : prefSum[n-1] - prefSum[r-1];
        ll tempAns = prefSum[n-1] - (num1+num2);
        ans = max(ans, tempAns);
    }

    cout << ans << nl;

    // int i=0, j=n-1;
    // // int sum1, sum2;
    // while(k--) {
    //     ll sum1=INT_MAX, sum2=INT_MAX;
    //     if(i+1<n) sum1 = arr[i]+arr[i+1];
    //     if(j>=0) sum2 = arr[j];
    //     if(sum1<sum2) {
    //         totSum -= sum1;
    //         i+=2;
    //     }
    //     else {
    //         totSum -= sum2;
    //         j--;
    //     }
    // }
    // cout << totSum << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}