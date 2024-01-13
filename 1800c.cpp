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
    multiset<int> st;
    int n; cin >> n;
    int x;
    long long sum=0;
    for(int i=0; i<n; ++i) {
        cin >> x;
        if(x==0) {
            if(!st.empty()) {
                sum += *st.rbegin();
                st.erase(st.find(*st.rbegin()));
            }
        }
        else st.insert(x);
    }
    cout << sum << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}