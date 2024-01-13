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
    int evenCnt=0, oddCnt=0;

    for(int i=0; i<n; ++i) {
        cin >> arr[i];
        if(arr[i]%2) oddCnt++;
        else evenCnt++;
    }

    if(n%2) {
        cout << "NO" << nl;
        return;
    }

    if(evenCnt%2==0) {
        cout << "YES" << nl;
        return;
    } 

    sort(arr.begin(), arr.end());

    for(int i=0; i<n-1; ++i) {
        if(arr[i+1]==arr[i]+1) {
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}