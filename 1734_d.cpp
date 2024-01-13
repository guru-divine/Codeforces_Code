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
    int n, pos; cin >> n >> pos;
    pos--;
    vi arr(n);
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
    }

    int leftMax = INT_MIN, rightMax = INT_MIN;
    int leftTotal = 0, rightTotal = 0;
    int sum = 0;
    for(int i=pos-1; i>=0; --i) {
        sum += arr[i];
        leftMax = max(leftMax, sum);
    }
    leftTotal = sum;
    sum = 0;
    for(int i=pos+1; i<n; ++i) {
        sum += arr[i];
        rightMax = max(rightMax, sum);
    }
    rightTotal = sum;
    bool leftPossible = (leftTotal+rightMax>=0);
    bool rightPossible = (rightTotal+leftMax>=0);
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