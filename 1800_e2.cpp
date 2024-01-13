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

void change(int i, int j, set<string> &vis, queue<string> &q, string t1) {
    if(i>=0 && i<j && j<sz(t1)) {
        swap(t1[i], t1[j]);
        if(vis.find(t1)==vis.end()) {
            vis.insert(t1);
            q.push(t1);
        }
    }
}

void func(string &t1, string &t2, int &k, bool &flag) {

    queue<string> q;
    set<string> vis;

    q.push(t1);

    while(!q.empty()) {
        t1 = q.front();
        if(t1==t2) {
            flag=1;
            return;
        }
        q.pop();
        fori(i, 0, sz(t2)) {
            change(i, i+k, vis, q, t1);
            change(i, i+k+1, vis, q, t1);
            change(i-k, i, vis, q, t1);
            change(i-k-1, i, vis, q, t1);
        }
    }
    
}

void solve() {
    int n, k; cin >> n >> k;
    string s1, s2;
    cin >> s1 >> s2;

    vi cnt(26, 0);
    fori(i, 0, n) cnt[s1[i]-'a']++;
    fori(i, 0, n) cnt[s2[i]-'a']--;

    if(n<2*k) {
        bool flag=0;
        func(s1, s2, k, flag);
        if(flag) cout << "YES" << nl;
        else cout << "NO" << nl;
    }
    else {
        fori(i, 0, 26) {
            if(cnt[i]!=0) {
                cout << "NO" << nl;
                return;
            }
        }
        cout << "YES" << nl;
    }


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