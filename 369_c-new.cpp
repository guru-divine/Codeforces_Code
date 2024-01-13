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

void dfs(int u, bool flag, vi &vis, vi revAdj[], vi &needRepair, set<int> &ans) {
    if(vis[u]) return;

    vis[u]=1;
    if(needRepair[u]==2) {
        if(!flag) {
            flag=1;
        }
        else ans.erase(u);
    }
    for(auto v: revAdj[u]) {
        dfs(v, flag, vis, revAdj, needRepair, ans);
    }
}

void solve() {
    int n; cin >> n;
    vector<int> revAdj[n+1];
    vi needRepair(n+1);
    vi indegree(n+1, 0);

    set<int> ans;

    map<int, vector<pii>> mp;
    fori(i, 0, n-1) {
        int u, v, t; cin >> u >> v >> t;
        mp[u].pb({v, t});
    }
    queue<int> qe;
    vi vis(n+1, 0);
    qe.push(1);
    vis[1]=1;
    while(!qe.empty()) {
        int u = qe.front();
        qe.pop();
        for(auto it: mp[u]) {
            int v = it.F;
            int t = it.S;
            if(!vis[v]) {
                vis[v]=1;
                qe.push(v);

                needRepair[v]=t;
                if(t==2) ans.insert(v);
                revAdj[v].pb(u);
                indegree[u]++;
            }
        }
    }
    set<pii> st;
    fori(i, 1, n+1) {
        if(!indegree[i]) {st.insert({-needRepair[i], i});}
    }

    fori(i, 0, n+1) vis[i]=0;
    while(!st.empty()) {
        auto it = st.begin();
        int u = (*it).S;
        // cout << u << " ";
        st.erase(it);
        dfs(u, 0, vis, revAdj, needRepair, ans);
    }
    // cout << nl;

    cout << sz(ans) << nl;
    for(auto it: ans) {
        cout << it << " ";
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