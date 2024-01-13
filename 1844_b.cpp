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
    if(n==1) cout << "1" << nl;
    else if(n==2) cout << "1 2" << nl;
    // else if(n==3) cout << "2 1 3" << nl;
    // else if(n==4) cout << "2 1 4 3" << nl;
    else {
        deque<int> q;
        // q.push_back(5);
        q.push_back(1);
        // q.push_back(4);
        fori(i, 4, n+1) {
            if(i%2==0) q.push_back(i);
            else q.push_front(i);
        }
        q.push_back(3);
        q.push_front(2);

        vi arr;
        while(!q.empty()) {
            int cur = q.front();
            arr.pb(cur);
            q.pop_front();
        }
        printS(arr);
    }

    
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