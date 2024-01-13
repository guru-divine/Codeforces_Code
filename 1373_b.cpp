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
    string str; cin >> str;
    int n = str.size();
    
    stack<char> st;
    int cnt=0;
    for(int i=0; i<n; ++i) {
        if(!st.empty()) {
            int node = st.top();
            if(str[i]!=node) {
                st.pop();
                cnt++;
            }
            else st.push(str[i]);
        }
        else st.push(str[i]);
    }
    if(cnt%2==1) cout<< "DA" << nl;
    else cout << "NET" << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}