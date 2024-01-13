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
    if(n>=0) {
        cout << n << nl;
        return;
    }
    else {
        if(n>-10) {
            cout << "0" << nl;
            return;
        }
        else {
            // int ans=0;
            int num = abs(n);
            if(num%10>((num%100)/10)) {
                int ans = (-1)*(num/10);
                cout << ans << nl;
            }
            else {
                int ans = num%10;
                ans += (num/100)*10;
                ans *= (-1);
                cout << ans << nl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}