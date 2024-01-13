//Author: DIVYA RAJ (aka guru_divine)
#include <bits/stdc++.h>
#define int long long
#define nl "\n"
#define vi vector<int>
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
using namespace std; 

void findMaxClosest(int &mini, int &num, vi &arr) {
    int lo = 0, hi = arr.size()-1;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        if(arr[mid]<=num) {
            mini = arr[mid];
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
}
void findMinClosest(int &maxi, int &num, vi &arr) {
    int lo = 0, hi = arr.size()-1;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        if(arr[mid]>=num) {
            maxi = arr[mid];
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
}
int square(int a) {return abs(a*a);}

void solve() {
    vi len(3);
    vi color[3];
    for(int i=0; i<3; ++i) {
        cin >> len[i];
        color[i].resize(len[i]);
    }
    for(int i=0; i<3; ++i) {
        for(int j=0; j<len[i]; ++j) cin >> color[i][j];
    }
    for(int i=0; i<3; ++i) sorti(color[i]);

    vi order = {1, 2, 3};
    int ans = LONG_LONG_MAX;
    do {
        int smallIdx, midIdx, largeIdx;
        for(int i=0; i<3; ++i) {
            if(order[i]==1) smallIdx = i;
            if(order[i]==2) midIdx = i;
            if(order[i]==3) largeIdx = i;
        }
        
        for(int i=0; i<color[midIdx].size(); ++i) {
            int mini = 0, maxi = 1e9+5;
            int cur = color[midIdx][i];
            findMaxClosest(mini, cur, color[smallIdx]);
            findMinClosest(maxi, cur, color[largeIdx]);
            if(mini==0 || maxi==1e9+5) continue;
            ans = min(ans, square(cur-mini)+square(maxi-cur)+square(maxi-mini));
        }
    }
    while(next_permutation(order.begin(), order.end()));
    cout << ans << nl;
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}