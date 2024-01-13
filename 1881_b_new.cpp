//Author: DIVYA RAJ (aka guru_divine)
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define nl "\n"
#define pb push_back
#define popb pop_back
#define F first
#define S second
#define sz(arr) (int)arr.size()
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define mapi map<int, int>
#define un_mapi unordered_map<int, int>
#define mod 1000000007
#define fori(i,a,b) for(int i=a; i<=b; ++i)
#define ford(i,a,b) for(int i=a; i>=b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reversei(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std; 

bool dp(int chance, multiset<int> &mst) {
    // for(auto it: mst) {
    //     cout << it << " ";
    // }
    // cout << nl; 
    if(chance==4) return false;
    if(*mst.begin()==*mst.rbegin()) return true;
    else {
        auto it = mst.end();
        it--;
        int num = *it;
        for(int i=1; i<=num/2; ++i) {
            mst.erase(mst.find(num));
            mst.insert(i), mst.insert(num-i);
            if(dp(chance+1, mst)==true) return true;
            mst.erase(i), mst.erase(num-i);
            mst.insert(num);
        }
    }
    return false;
}

void solve() {
    int a, b, c; cin >> a >> b >> c;
    multiset<int> mst;
    mst.insert(a), mst.insert(b), mst.insert(c);
    // dp(0, mst);
    bool flag = dp(0, mst);

    if(flag) cout << "YES" << nl;
    else cout << "NO" << nl;
}

signed main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}