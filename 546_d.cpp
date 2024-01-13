//Author: DIVYA RAJ (aka guru_divine)
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define nl "\n"
#define pb push_back
#define sz(arr) (int)arr.size()
using namespace std; 

void solve(vi &cntFactors) {
    int a, b; cin >> a >> b;
    int ans = cntFactors[a]-cntFactors[b];
    cout << ans << nl;
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vi isPrime(1e7, 1);

    for(int i=2; i<1e7; ++i) {
        if(isPrime[i]==1) {
            isPrime[i] = i;
            for(int j=i*i; j<1e7; j+=i) isPrime[j] = i;
        }
    }
    vi cntFactors(1e7);
    cntFactors[1] = 0;
    for(int i=2; i<1e7; ++i) {
        cntFactors[i] = cntFactors[i/isPrime[i]] + 1;
    }
    for(int i=1; i<1e7; ++i) {
        cntFactors[i] += cntFactors[i-1];
    }

    int t=1;
    cin >> t;
    while(t--) solve(cntFactors);
    return 0;
}