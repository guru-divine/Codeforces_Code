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
    vi ans;
    unordered_map<int, int> ump;

    // ans.pb(n);
    // if(n==1) {
    //     cout << ans[0] << nl;
    //     return;
    // }

    // ll sum = ans[0];
    // sum%=n;
    ll sum=0;

    int j=0, k=n-1;
    for(int i=0; i<n; ++i) {
        if(i%2==0) {
            if(j<=sum) {
                ans.pb(n-sum+j);
                if(ump[n-sum+j]==1) {
                    cout << "-1" << nl;
                    return;
                }
                ump[n-sum+j]=1;
                sum += (n-sum+j);
                sum%=n;
            }
            else {
                ans.pb(j-sum);
                if(ump[j-sum]==1) {
                    cout << "-1" << nl;
                    return;
                }
                ump[j-sum]=1;
                sum += (j-sum);
                sum%=n;
            }
            j++;
        }
        else {
            if(k<=sum) {
                ans.pb(n-sum+k);
                if(ump[n-sum+k]==1) {
                    cout << "-1" << nl;
                    return;
                }
                ump[n-sum+k]=1;
                sum += (n-sum+k);
                sum%=n;
            }
            else {
                ans.pb(k-sum);
                if(ump[k-sum]==1) {
                    cout << "-1" << nl;
                    return;
                }
                ump[k-sum]=1;
                sum += (k-sum);
                sum%=n;
            }
            k--;
        }
    } 

    for(int i=0; i<n; ++i) {
        cout << ans[i] << " ";
    }
    cout << nl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}