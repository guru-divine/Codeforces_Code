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
    ll n; cin >> n;
    vll arr(n);
    unordered_map<int, int> ump;

    ll maxNum=0, minNum=INT_MAX;
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
        ump[arr[i]]++;
        maxNum = max(maxNum, arr[i]);
        // minNum = min(minNum, arr[i]);
    } 
    vector<pair<int, int>> ans;
    ll cnt=0;

    for(auto it: ump) {
        ans.pb({it.first, it.second});
    }

    sort(ans.begin(), ans.end());

    // for(int i=0; i<ans.size(); ++i) {
    //     cout << ans[i].first << "->" << ans[i].second << " ";
    // }
    // cout << nl;

    for(int i=0; i<ans.size(); ++i) {

        int ocurr = ans[i].second;
        if(ocurr>=3) cnt += 1LL*(ocurr)*(ocurr-1)*(ocurr-2);

        for(int k=2; k<=sqrtl(1000000/ans[i].first)+2; ++k) {
            ll j = ans[i].first*k;
            ll num = j*k;
            if(num>maxNum) break;

            if(ump[j] && ump[num]) {
                cnt+=(1LL*ans[i].second*ump[j]*ump[num]);
            }
        }
    }

    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}