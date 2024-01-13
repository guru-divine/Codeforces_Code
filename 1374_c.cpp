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
    int n; cin >> n;
    string s; cin >> s;
    stack<char> st;
    for(int i=0; i<n; ++i) {
        if(!st.empty()) {
            int node = st.top();
            if(node=='(' && s[i]==')') st.pop();
            else st.push(s[i]);
        }
        else st.push(s[i]);
    }
    cout << st.size()/2 << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}