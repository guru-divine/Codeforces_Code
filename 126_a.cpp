//Author: DIVYA RAJ
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define nl "\n"
#define pb push_back
#define popb pop_back
#define F first
#define S second
#define sz(arr) arr.size()
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define mapi map<int, int>
#define un_mapi unordered_map<int, int>
#define mod 1000000007
#define fori(i,a,b) for(int i=a; i<b; ++i)
#define ford(i,a,b) for(int i=a; i>=b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reversei(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

void solve() {
    int t1, t2, x1, x2, t0;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    if(t1==t2) {
        cout << x1 << " " << x2 << nl;
        return;
    }
    int cof2 = t2-t0, cof1 = t0-t1;
    int mini = 1e18;
    int cold = 0, hot = 0;
    ford(i, x1, 0) {
        // cout << i << nl;
        if(cof2==0) {
            cold = 0, hot = x2;
            break;
        }
        int j = (cof1*i+cof2-1)/cof2;
        if(j<=x2) {
            if(i==j && i==0) j++;
            int diff = cof2*j - cof1*i;
            if(diff<mini) {
                mini = diff;
                cold = i;
                hot = j;
            }
        }
    }
    int minFact = 1;
    if(cold==0 && hot==0) {}
    else if(cold==0) minFact = x2/hot;
    else if(hot==0) minFact = x1/cold;
    else minFact = min(x2/hot, x1/cold);
    cold *= minFact;
    hot *= minFact;

    cout << cold << " " << hot << nl;
}

signed main() {
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}