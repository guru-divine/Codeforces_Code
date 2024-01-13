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
#define printS(arr) fori(i,0,arr.size()-1) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()-1) {cout << arr[i] << nl;}
using namespace std; 

void solve() {
    int n; cin >> n;
    vi arr(n);
    mapi mp;
    mapi vis;
    fori(i, 0, n-1) {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int cnt = 0, num = -1;
    for(auto it: mp) {
        if(it.S>=2) {
            cnt++;
            num = it.F;
        }
    }
    if(cnt<2) {
        cout << "-1" << nl;
        return;
    }

    vi brr(n);
    fori(i, 0, n-1) {
        if(mp[arr[i]]>=2) {
            if(arr[i]==num) {
                if(vis.find(arr[i])==vis.end()) {
                    brr[i] = 1;
                    vis[num]++;
                } else brr[i] = 2;
            } else {
                if(vis.find(arr[i])==vis.end()) {
                    brr[i] = 1;
                    vis[arr[i]]++;
                } else brr[i] = 3;
            }
        } else brr[i] = 1;
    }
    printS(brr);
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}