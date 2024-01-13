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
    int n, m, d; cin >> n >> m >> d;
    vector<pii> arr(n);
    multiset<pii> mst;
    fori(i, 0, n) {
        cin >> arr[i].F;
        arr[i].S = i;
        mst.insert({arr[i].F, arr[i].S});
    }

    sorti(arr);
    vi dayArr(n);

    int dayCnt=1;
    while(!mst.empty()) {
        auto it = mst.begin();
        dayArr[it->S]=dayCnt;
        int time = it->F;
        time += d+1;
        mst.erase(it);

        while(true) {
            it = mst.lower_bound({time, -1});
            if(it==mst.end()) break;
            time = it->F + d+1;
            dayArr[it->S] = dayCnt;
            mst.erase(it);
        }

        dayCnt++;
    }

    cout << dayCnt-1 << nl;
    printS(dayArr);

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