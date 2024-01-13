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
    vi adj[n+1];
    vi vis(n+1, 0), par(n+1);
    fori(i, 0, n+1) par[i]=i;

    fori(i, 0, n-1) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        // par[v]=u;
        adj[v].pb(u);
    }

    vi arr(n);
    fori(i, 0, n) cin >> arr[i];
    if(n==1) {
        cout << "YES" << nl;
        return;
    }
    if(arr[0]!=1) {
        cout << "NO" << nl;
        return;
    }

    queue<int> q;
    q.push(1);
    par[1]=1;
    vis[1]=1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto child: adj[node]) {
            if(!vis[child]) {
                vis[child]=1;
                par[child]=node;
                q.push(child);
            }
        }
    }

    int i=0;
    q.push(arr[i]);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        // i++;
        int cnt=0;
        if(!i) cnt--;
        while(cnt!=adj[node].size()-1) {
            i++;
            if(par[arr[i]]!=node) {
                cout << "NO" << nl;
                return;
            }
            q.push(arr[i]);
            cnt++;
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

    solve();
    return 0;
}