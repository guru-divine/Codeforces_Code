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
    int n, r1, r2; cin >> n >> r1 >> r2;
    int j=1;
    vi adj[n+1];

    fori(i, 0, n-1) {
        int x; cin >> x;
        if(j==r1) j++;
        adj[j].pb(x);
        adj[x].pb(j);
        j++;
    }

    vi par(n+1);
    queue<int> q;
    vi vis(n+1, 0);
    q.push(r2);
    vis[r2]=1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v: adj[u]) {
            if(!vis[v]) {
                vis[v]=1;
                par[v]=u;
                q.push(v);
            }
        }
    }
    fori(i, 1, n+1) {
        if(i==r2) continue;
        cout << par[i] << " ";
    }
    cout << nl;
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