//Author: DIVYA RAJ (aka guru_divine)
#include <bits/stdc++.h>
#define int long long
#define nl "\n"
#define vi vector<int>
#define pb push_back
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
using namespace std;  

void solve(vi &seive, vi &primes) {
    int n; cin >> n;
    map<int, int> mp;

    for(int i=0; i<n; ++i) {
        int num; cin >> num;
        int prevFact = 1;
        while(num!=1) {
            int curFact = seive[num];
            if(curFact!=prevFact) mp[curFact]++;
            num/=curFact;
            prevFact = curFact;
        }
    }
    int lastVal = 0;
    set<int> st;
    for(auto &it: mp) {
        lastVal += it.second;
        it.second = lastVal;
        st.insert(it.first);
    }
    // for(auto it: mp) {
    //     cout << it.first << "->" << it.second << nl;
    // }

    int m; cin >> m;
    while(m--) {
        int l, r; cin >> l >> r;
        auto itBig = st.upper_bound(r), itSmall = st.lower_bound(l);
        itBig--;
        if(*itBig<l) {
            cout << "0" << nl; continue;
        }
        int prefBig = *itBig, prefSmall;
        if(itSmall==st.begin()) prefSmall = 0;
        else {
            itSmall--; prefSmall = *itSmall;
        } 
        // cout << prefBig << " " << prefSmall << nl;
        cout << mp[prefBig] - mp[prefSmall] << nl;
    }
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vi seive(1e7+5, 1);
    vi primes;
    for(int i=2; i<seive.size(); ++i) {
        if(seive[i]==1) {
            seive[i] = i;
            primes.pb(i);
            for(int j=i*i; j<seive.size(); j+=i) {
                if(seive[j]==1) seive[j] = i;
            }
        }
    }
    int t=1;
    // cin >> t;
    while(t--) solve(seive, primes);
    return 0;
}