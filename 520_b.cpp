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
#define ford(i,a,b) for(int i=a; i<b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    if(m<=n) {
        cout << n-m << nl;
        return;
    }
    vi vis(20002, 0);
    vi adj[20002];
    fori(i, 1, 20002) {
        if(i>1) adj[i].pb(i-1);
        adj[i].pb(2*i);
    }

    queue<pii> q;
    q.push({n, 0});
    vis[n]=1;
    while(!q.empty()) {
        int node = q.front().F;
        int h = q.front().S;
        q.pop();

        for(auto child: adj[node]) {
            if(child>2*m) continue;
            if(!vis[child]) {
                if(child==m) {
                    cout << h+1 << nl;
                    return;
                }
                vis[child]=1;
                q.push({child, h+1});
            }
        }
    }
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}