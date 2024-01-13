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
    vi list = {4,7,44,47,74,77,444,447,474,477,744,747,774,777};
    int n; cin >> n;
    for(int i=0; i<list.size(); ++i) {
        if(list[i]>n) break;

        if(n%list[i]==0) {
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}