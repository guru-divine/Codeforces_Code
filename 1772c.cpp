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

// map<int, int> mp;

void solve() {
    int k, n;
    cin >> k >> n;
    int num=1, cnt=0;
    int temp=k;
    while(temp-- && num<=n) {
        cout << num << " ";
        // mp[num]++;
        cnt++;
        if((n-(num+cnt)+1)<temp) break;
        num+=cnt;
    }
    while(temp-->0) {
        num++;
        cout << num << " ";
    }
    cout << nl;

    // num-=cnt;
    // cout << num << nl << nl;
    // cout << mp.size() << nl;
    // cout << nl;
    // if(mp.size()<k) {
    //     int diff=k-mp.size();
    //     int upDiff=n-num;
    //     if(upDiff>=diff) {
    //         upDiff=diff;
    //         cout << upDiff << nl;
    //         diff=0;
    //     } else diff-=upDiff;
    //     for(int i=1; i<upDiff; ++i) {
    //         mp[num+i]++;
    //         cout << num+i << nl;
    //     } 
    //     while(diff) {
    //         num--;
    //         if(mp.find(num)!=mp.end()) {
    //             mp[num]++;
    //             diff--;
    //         }
    //     }
    // }
    // for(auto it=mp.begin(); it!=mp.end(); ++it) {
    //     cout << it->first <<" ";
    // }
    // cout << nl;
    // mp.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}