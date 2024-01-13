#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q, m;
    cin >> n;
    int x[n];
    for(int i=0; i<n; ++i) {
        cin >> x[i];
    }
    sort(x, x+n);
    cin >> q;
    for(int i=0; i<q; ++i) {
        cin >> m;
        cout << distance(x,upper_bound(x,x+n,m)) << endl;
    }
    return 0;
}