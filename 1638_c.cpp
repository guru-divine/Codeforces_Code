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
    int n; cin >> n;
    vi adj[n+1];
    vi p(n+1);

    fori(i, 1, n+1) {
        cin >> p[i];
    }

    stack<pii> st;
    fori(i, 1, n+1) {
        st.push({p[i], p[i]});
        while(st.size()>=2) {
            int min1 = st.top().F;
            pii top1 = st.top();
            st.pop();
            int max2 = st.top().S;
            if(max2>min1) {
                st.top().F = min(top1.F, st.top().F);
                st.top().S = max(top1.S, st.top().S);
            }
            else {
                st.push(top1);
                break;
            }
        }
    }

    cout << st.size() << nl;

    // fori(i, 1, n+1) {
    //     fori(j, i+1, n+1) {
    //         if(p[i]>p[j]) {
    //             adj[i].pb(j);
    //             adj[j].pb(i);
    //         }
    //     }
    // }

    // int cnt=0;
    // vi vis(n+1, 0);
    // queue<int> q;

    // fori(i, 1, n+1) {
    //     if(!vis[i]) {
    //         vis[i]=1;
    //         q.push(i);

    //         while(!q.empty()) {
    //             int node = q.front();
    //             vis[node]=1;
    //             q.pop();

    //             for(auto child: adj[node]) {
    //                 if(!vis[child]) {
    //                     vis[child]=1;
    //                     q.push(child);
    //                 }  
    //             }
    //         }
    //         cnt++;
    //     }
    // }

    // cout << cnt << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}