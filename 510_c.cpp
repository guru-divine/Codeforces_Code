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
#define printS(arr) fori(i,0,arr.size()-1) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std; 

void solve() {
    int n; cin >> n;
    vs str_arr(n);
    fori(i, 0, n-1) cin >> str_arr[i];

    vi indegree(26, 0);
    vi char_adj[26];
    fori(i, 0, n-2) {
        int idx = 0;
        for(int j=0; j<min(sz(str_arr[i]), sz(str_arr[i+1])); ++j) {
            if(str_arr[i][j]!=str_arr[i+1][j]) break;
            idx++;
        }
        if(idx==min(sz(str_arr[i]), sz(str_arr[i+1]))) {
            if(sz(str_arr[i])>sz(str_arr[i+1])) {
                cout << "Impossible" << nl;
                return;
            }
        }
        else {
            // idx--;
            indegree[str_arr[i+1][idx]-'a']++;
            char_adj[str_arr[i][idx]-'a'].pb(str_arr[i+1][idx]-'a');
        }
        // cout << idx << nl;
    }
    // printS(indegree);
    queue<int> q;
    fori(i, 0, 25) {
        if(!indegree[i]) q.push(i);
    }
    string ans;
    while(!q.empty()) {
        int u = q.front();
        ans.pb('a'+u);
        q.pop();
        for(auto v: char_adj[u]) {
            indegree[v]--;
            if(!indegree[v]) q.push(v);
        }
    }
    if(sz(ans)==26) cout << ans << nl;
    else cout << "Impossible" << nl;
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}