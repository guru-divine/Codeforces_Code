#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int maxNum = 0;
    for(int i=0; i<n; ++i) {
        cin >> a[i];
        maxNum = max(a[i], maxNum);
    }
    int maxDigNum = maxNum;
    int minDigNum = maxNum;
    for(int i=0; i<n; ++i) {
        maxDigNum |= a[i];
        minDigNum &= a[i];
    }
    cout << maxDigNum - minDigNum << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}