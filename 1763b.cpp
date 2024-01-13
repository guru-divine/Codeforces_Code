#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, k, maxNum;
    cin >> n >> k;
    int h[n], p[n];
    maxNum = 0;
    for(int i=0; i<n; ++i) {
        cin >> h[i];
        maxNum = max(maxNum, h[i]);
    }
    for(int i=0; i<n; ++i) {
        cin >> p[i];
    }
    int flag=0, minNum=INT_MAX, minI;
    while(flag==0) {
        for(int i=0; i<n; ++i) {
            h[i] -= k;
            maxNum -= k;
            if(maxNum <= 0) {
                flag = 2;
                break;
            }
            if(h[i]<0) h[i]=0;
            if(h[i]) {
                minNum = (h[i] < minNum) ? h[i] : minNum;
                if(minNum == h[i]) minI = i;
            }
        }
        if(flag==0) {
            k -= p[minI];
            if(k<=0) flag=1;
        }
        
    }
    if(flag==2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}