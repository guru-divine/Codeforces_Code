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

int binPow(int a, int n) {
    int ans = 1;
    while(n) {
        if(n&1) ans = (ans*a);
        a = (a*a);
        n >>= 1;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vi arr(n);
    fori(i, 0, n) {
        cin >> arr[i];
    }
    sorti(arr);
    
    int miniAns = 1e18;
    int c = 1;
    while(true) {
        int curAns = 0;
        int num = 1;

        fori(i, 0, n) {
            curAns += abs(arr[i]-num);
            num *= c;
            if(num>1e15) {
                cout << miniAns << nl;
                return;
            }
        }

        miniAns = min(miniAns, curAns);
        c++;
    }

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