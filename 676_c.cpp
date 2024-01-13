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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    s.insert(s.begin(), '#');
    vi prefA(n+1, 0), prefB(n+1, 0);
    fori(i, 1, n) {
        if(s[i]=='a') {
            prefA[i] = prefA[i-1]+1;
            prefB[i] = prefB[i-1];
        }
        else {
            prefB[i] = prefB[i-1]+1;
            prefA[i] = prefA[i-1];
        }
    } 
    // printS(prefA);
    // printS(prefB);

    int maxiA = 0, maxiB = 0;
    fori(i, 1, n) {
        int lo = i, hi = n;
        while(lo<=hi) {
            int mid = (lo+hi)/2;
            if(prefA[mid]-prefA[i-1]<=k) {
                maxiB = max(maxiB, mid-i+1);
                lo = mid+1;
            }
            else hi = mid-1;
        }

        lo = i, hi = n;
        while(lo<=hi) {
            int mid = (lo+hi)/2;
            if(prefB[mid]-prefB[i-1]<=k) {
                maxiA = max(maxiA, mid-i+1);
                lo = mid+1;
            }
            else hi = mid-1;
        }
    }

    int ans = max(maxiA, maxiB);
    cout << ans << nl;
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}