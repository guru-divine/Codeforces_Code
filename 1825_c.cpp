//Author: guru_divine
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mod 1000000007
using namespace std;

void solve() {
    set<int>st;
    unordered_map<int, int> ump;
    int n, m; cin >> n >> m;
    int cnt1=0, cnt2=0;
    for(int i=0; i<n; ++i) {
        int x; cin >> x;
        if(x==-1) cnt1++;
        else if(x==-2) cnt2++;
        else st.insert(x);
    }
    int stSize=st.size();
    if(stSize==0) {
        int finalAns = max(min(cnt1, m), min(cnt2, m));
        cout << finalAns << nl;
        return;
    }

    // Case 1: choose -2 first
    int ans1 = stSize + min(cnt2, m-stSize);
    // Case 2: Choose -1 first
    int ans2 = stSize + min(cnt1, m-stSize);
    //Case 3: Choose >0 wisely
    int ans3=0;
    int i=0;
    for(auto it: st) {
        int pos=it;
        int ans = min(cnt1, pos-1-i) + stSize + min(cnt2, m-pos-(stSize-1-i));
        ans3 = max(ans3, ans);
        i++;
    }

    int finalAns = max(max(ans1, ans2), ans3);
    cout << finalAns << nl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}