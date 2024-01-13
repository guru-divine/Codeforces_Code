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
    mapi mp;
    int maxi = 0, maxElem=-1;
    fori(i, 0, n-1) {
        cin >> arr[i];
        if(mp.find(arr[i]-1)!=mp.end()) {
            mp[arr[i]] = mp[arr[i]-1] + 1;
            if(mp[arr[i]]>maxi) {
                maxi = mp[arr[i]];
                maxElem = arr[i];
            }
        }
        else {
            mp[arr[i]] = 1;
            if(mp[arr[i]]>maxi) {
                maxi = mp[arr[i]];
                maxElem = arr[i];
            }
        }
    }
    
    vi ansIdx;
    ford(i, n-1, 0) {
        if(arr[i]==maxElem) {
            ansIdx.pb(i+1);
            maxElem--;
        }
    }

    reversei(ansIdx);
    cout << sz(ansIdx) << nl;
    printS(ansIdx);
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