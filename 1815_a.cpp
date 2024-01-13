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

        vi arr(n);
        for(int i=0; i<n; ++i) {
            cin >> arr[i];
        }

        if(n%2==1) {
            cout << "YES" << nl;
            return;
        }

        vi diff;
        ll sum=0;

        for(int i=0; i<n-1; ++i) {
            diff.pb(arr[i+1]-arr[i]);
            if(i%2==0) sum+=diff[i];
        }

        if(sum>=0) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int t; cin >> t;
        while(t--) solve();
        return 0;
    }