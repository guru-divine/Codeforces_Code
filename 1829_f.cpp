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
    int n, m; cin >> n >> m;
    unordered_map<int, int> ump;
    set<int> st;
    vector<int> adj[n+1];
    for(int i=0; i<m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(int i=1; i<=n; ++i) {
        int freq = adj[i].size();
        // cout << freq << " ";
        ump[i]=freq;
        st.insert(freq);
    }

    // cout << st.size() << nl;
    // if(st.size()==2) {

    // }
    // cout << st.size() << nl;
    auto it = st.begin();
    it++;
    int num1 = *it;
    if(st.size()==3) it++;
    int num2 = *it;

    int cnt1=0, cnt2=0;
    for(auto itr: ump) {
        if(itr.second==num1) cnt1++;
        if(itr.second==num2) cnt2++;
    }

    if(cnt1==1) {
        cout << num1 << " " << num2-1 << nl;
        return;
    }
    else {
        cout << num2 << " " << num1-1 << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}