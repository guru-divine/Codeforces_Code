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
    int zeroNum=0, negNum=0;
    ll sum=0;
    for(int i=0; i<n; ++i) {
        ll x; cin >> x;
        if(x>0) {
            sum += abs(x-1);
        }
        else if(x==0) {
            zeroNum++;
            sum++;
        }
        else {
            negNum++;
            sum+= abs(x+1);
        }
    }
    if(negNum%2 && !zeroNum) sum+=2;
    cout << sum << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}