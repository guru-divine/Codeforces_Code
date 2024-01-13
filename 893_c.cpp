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
    vi adj[n], price(n);

    fori(i, 0, n) {
        cin >> price[i];
    }

    while(m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int ans=0;

    vi vis(n, 0);
    queue<int> q;

    fori(i, 0, n) {
        if(!vis[i]) {
            int mini = INT_MAX;
            vis[i]=1;
            q.push(i);

            while(!q.empty()) {
                int node = q.front();
                vis[node]=1;
                mini = min(mini, price[node]);
                q.pop();

                for(auto child: adj[node]) {
                    if(!vis[child]) {
                        vis[child]=1;
                        q.push(child);
                    }  
                }
            }
            ans += mini;
        }
    }

    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}