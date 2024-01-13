//Author: DIVYA RAJ
#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define pb push_back
#define popb pop_back
#define F first
#define S second
#define sz(arr) arr.size()
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define map map<int, int>
#define un_map unordered_map<int, int>
#define mod 1000000007
#define fori(i,a,b) for(int i=a; i<b; ++i)
#define forll(i,a,b) for(ll i=a; i<b; ++i)
#define ford(i,a,b) for(int i=a; i<b; --i)
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

void solve() {
    ll n; cin >> n;
    if(n<2) {
        cout << "0" << nl;
        return;
    }
    set<int> st;

    int h=1;
    while(true) {
        int num = (h*(3*h+1))/2;
        st.insert(num);
        if(num>n) break;
        h++;
    }

    int diff=n;
    int cnt=0;
    while(true) {
        auto it = lower_bound(st.begin(), st.end(), diff);
        if(*it==diff) {
            cnt++;
            break;
        }
        if(it==st.begin()) break;
        it--;
        diff -= *it;
        cnt++;
    }

    cout << cnt << nl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}