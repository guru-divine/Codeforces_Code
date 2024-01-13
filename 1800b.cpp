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
    int n, k;
    cin >> n >> k;
    string str; cin >> str;
    
    vector<int> lower(26, 0), upper(26, 0);
    // vector<int> charCnt(26, 0);
    for(int i=0; i<n; ++i) {
        if(str[i]>='a') lower[str[i]-'a']++;
        else upper[str[i]-'A']++;
    }
    
    int cnt=0;
    for(int i=0; i<n; ++i) {
        int temp = min(lower[i], upper[i]);
        lower[i] -= temp;
        upper[i] -= temp;
        cnt += temp;
    }
    int extraCnt=0;
    for(int i=0; i<n; ++i) {
        extraCnt += abs(lower[i]-upper[i])/2;
        if (extraCnt >= k) {
            extraCnt = k;
            break;
        }
    }
    cnt += extraCnt;
    cout << cnt << nl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t; cin >> t;
    while(t--) solve();
    return 0;
}