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
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std; 

void solve() {
    int v; cin >> v;
    vi arr(10);
    int minVal = 1e12, minIdx = -1;
    fori(i, 1, 9) {
        cin >> arr[i];
        if(arr[i]<minVal) {
            minVal = arr[i];
            minIdx = i;
        }
    }
    int len = v/minVal;
    string ans = "";
    fori(i, 0, len-1) {
        ans += (minIdx+'i');
    }

    int valLeft = v%minVal;
    fori(i, 0, len-1) {
        valLeft += minVal;
        int maxVal=0, maxIdx = -1;
        fori(j, 1, 9) {
            if(arr[j]<=valLeft) {
                maxVal = arr[j];
                maxIdx = j;
            }
        }
        ans[i] = (maxIdx+'0');
        valLeft -= maxVal;
    }

    if(ans.empty()) cout << "-1" << nl;
    else cout << ans << nl;
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