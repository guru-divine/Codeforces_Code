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
    int n; cin >> n;
    map<int, int> mp;
    fori(i, 0, n) {
        int x; cin >> x;
        mp[x]++;
    }

    int q; cin >> q;
    while(q--) {
        int x, y; cin >> x >> y;
        int num = (x*x)-(4*y);
        if(num<0) {
            cout << "0 ";
            continue;
        }

        int sqrtNum = sqrt(num);
        if(sqrtNum*sqrtNum==num) {
            if(abs(x+sqrtNum)%2==1) cout << "0 ";
            else {
                int a = (x+sqrtNum)/2;
                int b = (x-sqrtNum)/2;
                int ans = 0;
                if(a==b && mp.find(a)!=mp.end()) {
                    ans = ((mp[a])*(mp[a]-1))/2;
                }
                else if(mp.find(a)!=mp.end() && mp.find(b)!=mp.end()) {
                    ans = mp[a]*mp[b];
                }
                cout << ans << " ";
            }
            
        }
        else cout << "0" << " ";
    }
    cout << nl;
}

signed main() {
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}