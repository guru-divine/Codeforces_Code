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
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std; 

void dfs(int u, vector<set<int>> adj, vi &dist) {
    for(auto v: adj[u]) {
        if(!dist[v]) {
            dist[v] = dist[u]+1;
            dfs(v, adj, dist);
        }
    }
}

void solve() {
    int n, k; cin >> n >> k;
    vi marked(n+1, 0);
    int marki;
    fori(i, 0, k-1) {
        int x; cin >> x;
        marki = x;
        marked[x]=1;
    }
    mapi mp;
    vector<set<int>> adj(n+1);
    fori(i, 0, n-2) {
        int u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    queue<int> q;
    fori(i, 1, n) {
        if(sz(adj[i])==1) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v: adj[u]) {
            if(!marked[v]) {
                q.push(v);
                adj[u].erase(v);
                adj[v].erase(u);
            }
        }
    }

    int maxDist = 0, maxIdx = 0;
    vi dist(n, 0);
    dist[marki]=1;
    dfs(marki, adj, dist);
    fori(i, 1, n) {
        if(dist[i]>maxDist) {
            maxDist = dist[i];
            maxIdx = i;
        }
    }
    fori(i, 1, n) dist[i]=0;
    dist[maxIdx]=1;
    dfs(maxIdx, adj, dist);
    fori(i, 1, n) {
        maxDist = max(maxDist, dist[i]-1);
    } 

    int ans = (maxDist+1)/2;
    cout << ans << nl;
}

signed main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}