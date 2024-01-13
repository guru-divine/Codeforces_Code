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
    if(n>45) {
        cout << "-1" << nl;
        return;
    }
    int remSum = n;

    string str="";

    for(int i=9; i>0; --i) {
        if(remSum < i) {
            // cout << remSum;
            str.push_back(remSum + '0');
            break;
        }
        str.push_back(i + '0');
        remSum -= i;
        // cout << i;
    }
    // cout << str << nl;

    reverse(str.begin(), str.end());
    int num = stoi(str);
    cout << num << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}