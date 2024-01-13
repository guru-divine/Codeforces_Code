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

    if(n==1) {
        cout << "0" << nl;
        return;
    }

    sort(arr.begin(), arr.end());
    int cnt=1, maxSame=0;
    int distCnt=1;

    for(int i=0; i<n-1; ++i) {
        if(arr[i]==arr[i+1]) cnt++;
        else {
            distCnt++;
            maxSame = max(maxSame, cnt);
            cnt=1;
        }
    }
    maxSame = max(maxSame, cnt);
    if(distCnt!=maxSame) cout << min(distCnt, maxSame) << nl;
    else cout << distCnt-1 << nl;
    // cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}