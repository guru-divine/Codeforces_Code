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
    // un_mapi set1, set2;
    bool flag=0;
    // fori(i, 0, n) {
    //     int u, v; cin >> u >> v;
    //     if(flag) continue;
    //     else if(u==v) flag=1;
    //     else if((set1[u] || set1[v]) && (set2[u] || set2[v])) flag=1;
    //     else if(set1[u]==0 && set1[v]==0) {
    //         set1[u]++; set1[v]++;
    //     }
    //     else if(set2[u]==0 && set2[v]==0) {
    //         set2[u]++; set2[v]++;
    //     }
    // }
    // if(set1.size()!=set2.size()) flag=1;

    vi adj[n];
    fori(i, 0, n) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(v);

        if(u==v) flag=1;
    }

    if(flag) {
        cout << "NO:)" << nl;
        return;
    }

    vi color(n, -1), vis(n, 0);
    queue<int> q;
    fori(i, 0, n) {
        if(!vis[i]) {
            vis[i]=1;
            color[i]=0;
            q.push(i);
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                for(auto child: adj[node]) {
                    if(!vis[child]) {
                        vis[child]=1;
                        color[child]=!color[node];
                        q.push(child);
                    }
                    else if(child!=node && color[child]==color[node]) {
                        cout << "NO:(" << nl;
                        // cout << child << " " << node << nl;
                        // printS(color);
                        return;
                    }
                }
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