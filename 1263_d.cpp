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

int findPar(int node, vi &par) {
    if(node==par[node]) return node;

    return par[node] = findPar(par[node], par);
}

void merge(int x, int y, vi &par, vi &size) {
    int parx = par[x];
    int pary = par[y];
    if(parx==pary) return;

    if(size[parx]>=size[pary]) {
        par[pary] = parx;
        size[parx] += size[pary];
        size[pary]=0;
    } else {
        par[parx] = pary;
        size[pary] += size[parx];
        size[parx]=0;
    }
}

void solve() {
    un_mapi ump;
    int n; cin >> n;

    vi adj[26];
    vi par(26), size(26, 1);
    fori(i, 0, 26) par[i] = i;

    while(n--) {
        string s; cin >> s;
        int x = s[0]-'a';
        ump[x]++;
        for(int i=1; i<s.size(); ++i) {
            int y = s[i]-'a';
            ump[y]++;
            merge(x, y, par, size);
        }
    }

    int minPas=0;
    fori(i, 0, 26) {
        if(par[i]==i && ump[i]) {
            minPas++;
        }
    }

    cout << minPas << nl;
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