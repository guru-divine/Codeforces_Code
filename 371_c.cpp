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

bool cmp(pair<pii, int> a, pair<pii, int> b) {
    return (a.F.S * b.F.F < b.F.S * a.F.F);
}

void solve() {
    string s; cin >> s;
    vi cnt(3, 0);
    vi marked(3, 0);
    fori(i, 0, sz(s)) {
        if(s[i]=='B') cnt[0]++;
        else if(s[i]=='S') cnt[1]++;
        else cnt[2]++;
    }
    fori(i, 0, 3) {
        if(!cnt[i]) marked[i]=1;
    }

    vi numb(3, 0);
    cin >> numb[0] >> numb[1] >> numb[2];

    vi price(3);
    cin >> price[0] >> price[1] >> price[2];

    int paisa; cin >> paisa;

    vector<pair<pii, int>> ham;
    fori(i, 0, 3) {
        if(!marked[i]) ham.pb({{cnt[i], numb[i]}, price[i]});
    }
    // sort(all(ham), cmp);

    int lo = 0, hi = 1e12+300;
    int ans = 0;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        int money = 0;
        fori(i, 0, sz(ham)) {
            if(ham[i].F.S/ham[i].F.F >= mid) continue;
            else money += (mid*ham[i].F.F - ham[i].F.S)*ham[i].S;
        }
        if(money>paisa) hi = mid-1;
        else {
            lo = mid+1;
            ans = mid;
        }
    }
    cout << ans << nl;

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