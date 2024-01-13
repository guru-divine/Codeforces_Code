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
    fori(i, 0, n-1) {
        cin >> arr[i];
    }
    sorti(arr);
    vi brr(n);
    int i=0, j=n-1, k=0;

    int sum = 0;
    while(i<=j) {
        if(sum>=0) {
            sum += arr[i];
            brr[k++] = arr[i++];
        }
        else {
            sum += arr[j];
            brr[k++] = arr[j--];
        }
    }
    int maxDiff = arr[n-1] - arr[0];
    int maxSum = 0, curSum=0;
    fori(i, 0, n-1) {
        curSum += brr[i];
        if(brr[i]<0) curSum = 0;
        maxSum = max(maxSum, curSum); 
    }

    if(maxSum<maxDiff) {
        cout << "Yes" << nl;
        printS(brr);
    }
    else cout << "No" << nl;
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