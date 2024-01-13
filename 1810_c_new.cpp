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
    ll n, deleteCost, insertCost;
    cin >> n >> deleteCost >> insertCost;

    ll dupCnt=0;
    unordered_map<int, int> ump;

    vi arr;

    for(int i=0; i<n; ++i) {
        int x; cin >> x;

        if(ump[x]) dupCnt++;
        else {
            ump[x]=1;
            arr.pb(x);
        }
    }

    sort(arr.begin(), arr.end());

    ll ans = dupCnt*deleteCost;
    int num = 0, flag=0;

    int len = arr.size();
    for(int i=0; i<len; ++i) {
        if(flag==1) break;

        if(arr[i]==num+1) {
            num = arr[i];
        }
        else {
            int diff = arr[i]-num-1;

            if((deleteCost*(len-i))<=(insertCost*diff)) {
                ans += deleteCost*(len-i);
                break;
            }
            else {
                ans += insertCost*diff;
                num = arr[i];
            }
        }
        // cout << ans << " ";
    }

    ll temp = deleteCost*n + insertCost;

    ans = min(ans, temp);
    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}