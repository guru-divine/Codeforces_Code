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
    int n, k;
    cin >> n >> k;
    int time = 240-k;
    int lo=0;
    int hi=n;
    int ans=0;
    while(lo<=hi) {
        int mid=(lo+hi)/2;
        if((5*mid*(mid+1))/2<=time) {
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}