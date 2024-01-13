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
    vi arr(n-1);
    multiset<int> mst, mst2;
    fori(i, 0, n-1) {
        cin >> arr[i];
        if(!i) mst.insert(arr[i]);
        else mst.insert(arr[i]-arr[i-1]);
    }
    if(arr[n-2]>(n*(n+1))/2) {
        cout << "NO" << nl;
        return;
    }

    int j=1;
    vector<bool> marked(n+1, 0);
    marked[0]=1;
    int cnt=0;
    // int misNum = -1;
    for(auto it: mst) {
        if(it<=n && marked[it]==0) {
            marked[it]=1;
            cnt++;
            // mst.erase(mst.find(it));
        }
        else mst2.insert(it);
    }
    if(mst2.size()==0) {
        if(cnt==n-1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }
    else if(mst2.size()==1) {
        int num = *mst2.begin();
        // int num=0;
        if(cnt==n-2) {
            fori(i, 1, n+1) {
                if(!marked[i]) num-=i;
            }
            if(num==0) cout << "YES" << nl;
            else cout << "NO" << nl;
        }
        else cout << "NO" << nl;
    }
    else cout << "NO" << nl;
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