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
    int n; cin >> n;
    vi ans;
    if(n%2==0) cout << "-1" << nl;
    else if(n==1) cout << "0" << nl;
    else {
        ll num;
        for(int i=0; i<=31; ++i) {
            num = (1<<i);
            if(num>n) break;
        }
        // cout << num << "*" << nl;
        ll befNum = num/2;;
        while(n!=1) {
            ll temp = (n+1)/2;
            if(temp%2==0) {
                ans.pb(2);
                n = (n-1)/2;
                befNum/=2;
                num/=2;
            }
            else {
                ans.pb(1);
                n = (n+1)/2;
                befNum/=2;
                num/=2;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << nl;
        for(int i=0; i<ans.size(); ++i) {
            cout << ans[i] << " ";
        }
        cout << nl;
    }
}

void solve1() {
    int n; cin >> n;
    vi ans;
    if(n%2==0) {
        cout << "-1" << nl;
        return;
    }
    else {
        n = (n-1)/2;
        while(n) {
            if(n%2==0) ans.pb(1);
            else ans.pb(2);
            n/=2;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << nl;
    for(int i=0; i<ans.size(); ++i) {
        cout << ans[i] << " "; 
    }
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve1();
    return 0;
}