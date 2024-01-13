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
    int arr[4];
    int minNum=105;
    int maxNum=0;
    int minIdx, maxIdx;
    for(int i=0; i<4; ++i) {
        cin >> arr[i];
    }
    swap(arr[2], arr[3]);

    for(int i=0; i<4; ++i) {
        // cin >> arr[i];
        if(arr[i]<minNum) {
            minNum=arr[i];
            minIdx=i;
        }
        if(arr[i]>maxNum) {
            maxNum=arr[i];
            maxIdx=i;
        }
    }
    if(abs(maxIdx-minIdx)==2) cout << "YES" <<nl;
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