#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<int, int> ump;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll cnt=0;
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; ++i) {
            cin >> a[i];
            ump[a[i]-i]++;
        }
        for(auto it=ump.begin(); it!=ump.end(); ++it) {
            cnt+= (1LL*(it->second)*((it->second)-1))/2;
        }
        cout << cnt << endl;
        ump.clear();
    }
    return 0;
}