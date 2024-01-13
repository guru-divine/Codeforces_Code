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
    fori(i, 0, n) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi indegree(n), vis(n, 0);
    queue<int> q;
    fori(i, 0, n) {
        indegree[i] = adj[i].size();
        if(indegree[i]==1) {
            q.push(i);
            vis[i]=1;
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v: adj[u]) {
            indegree[v]--;
            if(indegree[v]==1) {
                q.push(v);
                vis[v]=1;
            }
        }
    }
    vi arr;
    fori(i, 0, n) {
        if(!vis[i]) arr.pb(i);
    }
    vi dist(n, 1e9);
    set<pii> st;

    fori(i, 0, sz(arr)) {
        dist[arr[i]]=0;
        st.insert({0, arr[i]});
    }


    while(!st.empty()) {
        auto it = *st.begin();
        int u = it.S;
        int disU = it.F;
        st.erase(it);

        for(auto v: adj[u]) {
            if(disU+1<dist[v]) {
                if(dist[v]!=1e9) st.erase(st.find({dist[v], v}));
                dist[v] = disU+1;
                st.insert({dist[v], v});
            }
        }
    }

    printS(dist);

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