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
    int a, b, c;
    cin >> a >> b >> c;
    int maxNum = 0;
    maxNum = max(maxNum, a+b+c);
    maxNum = max(maxNum, a*b*c);
    maxNum = max(maxNum, (a*b)+c);
    maxNum = max(maxNum, a+(b*c));
    maxNum = max(maxNum, (a+b)*c);
    maxNum = max(maxNum, a*(b+c));
    // maxNum = max(maxNum, );

    cout << maxNum << nl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}