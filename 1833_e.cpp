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

// int findPar(int node, vi &par) {
//     if(node==par[node]) return node;

//     return par[node] = findPar(par[node], par);
// }

// void merge(int x, int y, vi &par, vi &size) {
//     int parx = par[x];
//     int pary = par[y];
//     if(parx==pary) return;

//     if(size[parx]>=size[pary]) {
//         par[pary] = parx;
//         size[parx] += size[pary];
//         size[pary]=0;
//     } else {
//         par[parx] = pary;
//         size[pary] += size[parx];
//         size[parx]=0;
//     }
// }

void solve() {
    int n; cin >> n;
    vi par(n), size(n, 1);
    vector<set<int>> adj(n);
    fori(i, 0, n) par[i]=i;

    fori(i, 0, n) {
        int x; cin >> x;
        x--;
        adj[i].insert(x);
        adj[x].insert(i);
        // merge(i, x, par, size);
    }

    int cntCycle=0, cntPath=0;
    vi vis(n, 0);
    queue<int> q;
    fori(i, 0, n) {
        if(!vis[i]) {
            int flag=0;
            vis[i]=1;
            q.push(i);
            while(!q.empty()) {
                int node = q.front();
                if(adj[node].size()==1) flag=1;
                q.pop();
                for(auto child: adj[node]) {
                    if(!vis[child]) {
                        vis[child]=1;
                        q.push(child);
                    }
                }
            }
            if(flag) cntPath++;
            else cntCycle++;
        }
    }

    cout << cntCycle+min(cntPath, 1LL*1) << " " << cntCycle+cntPath << nl;

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