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
    int n, m; cin >> n >> m;
    vi arr(n*m);
    for(int i=0; i<arr.size(); ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int length = max(n, m);
    int breadth = min(n, m);

    int minNum = arr[0];
    int secMinNum = arr[1];
    int maxNum = arr[arr.size()-1];
    int secMaxNum = arr[arr.size()-2];

    ll ans1 = 1LL*(maxNum-minNum)*breadth*(length-1) + 1LL*(maxNum-secMinNum)*(breadth-1);
    ll ans2 = 1LL*(maxNum-minNum)*breadth*(length-1) + 1LL*(secMaxNum-minNum)*(breadth-1);
    cout << max(ans1, ans2) << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}