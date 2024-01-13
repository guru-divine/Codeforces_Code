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

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vi arr(n), par(26);
    fori(i, 0, n) {
        arr[i] = s[i]-'a';
    }
    fori(i, 0, 26) par[i]=i;

    int maxi = 0;
    int i=0, flag=0;
    while(i<n) {
        for(int j=arr[i]; j>maxi; --j) {
            if(!k) {
                flag=1;
                break;
            }
            par[j] = j-1;
            k--;
        }
        if(flag) break;
        maxi = max(maxi, arr[i]);
        i++;
    }

    fori(i, 0, n) {
        arr[i] = findPar(arr[i], par);
        s[i] = arr[i]+'a';
    }

    cout << s << nl;
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