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
    vi adj[n];

    bool flag=0;
    fori(i, 0, n) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
        if(u==v || adj[u].size()>2 || adj[v].size()>2) flag=1;
    }

    if(flag) {
        cout << "NO" << nl;
        return;
    }

    queue<int> q;
    vi vis(n, 0);
    fori(i, 0, n) {
        if(!vis[i]) {
            int cnt=0;
            vis[i]=1;
            q.push(i);
            while(!q.empty()) {
                int u = q.front();
                cnt++;
                q.pop();
                for(auto v: adj[u]) {
                    if(!vis[v]) {
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
            if(cnt&1) {
                cout << "NO" << nl;
                return;
            }
        }
    }
    cout << "YES" << nl;
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