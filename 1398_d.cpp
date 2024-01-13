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

int dp(vi &idx, vi col[], vi &memo) {
    int flag = (idx[0]==sz(col[0])) + (idx[1]==sz(col[1])) + (idx[2]==sz(col[2]));
    if(flag>1) return 0;

    int ans = 0;

    if(flag==1) {
        fori(i, 0, 3) {
            if(idx[i]==col[i].size()) {
                int j = (i+1)%3;
                int k = (i+2)%3;
                idx[j]++, idx[k]++;
                ans = max(ans, dp(idx, col, memo)+(col[j][idx[j]-1]*col[k][idx[k]-1]));
                idx[j]--, idx[k]--;
            }
        }
    }
    else {
        int mini = min(col[0][idx[0]], min(col[1][idx[1]], col[2][idx[2]]));
        fori(i, 0, 3) {
            if(col[i][idx[i]]==mini) {
                int j = (i+1)%3;
                int k = (i+2)%3;
                idx[j]++, idx[k]++;
                ans = max(ans, dp(idx, col, memo)+(col[j][idx[j]-1]*col[k][idx[k]-1]));
                idx[j]--, idx[k]--;
            }
        }
        
    }
    return ans;
}

void solve() {
    int r, g, b; cin >> r >> g >> b;
    vi col[3];
    vi arr(r), brr(g), crr(b);
    
    fori(i, 0, r) cin >> arr[i];
    fori(i, 0, g) cin >> brr[i];
    fori(i, 0, b) cin >> crr[i];

    sortd(arr); sortd(brr); sortd(crr);
    col[0] = arr, col[1] = brr, col[2] = crr;

    vi idx(3, 0);
    int ans = 0;

    vi memo;
    cout << dp(idx, col, memo) << nl;
}

signed main() {
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}