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
    // if(n==1) {
    //     cout << "1" << nl;
    //     return;
    // }
    // if(n==2) {
    //     cout << "11" << nl;
    //     return;
    // }
    vi arr(n);
    fori(i, 0, n) {
        cin >> arr[i];
    }

    vi marked(n, 0);

    int init = arr[0];
    int lastNum=-1, flag=0;
    int firstFlag=1;
    fori(i, 0, n) {
        if(!flag) {
            if(arr[i]>=lastNum) {
                marked[i]=1;
                lastNum=arr[i];
            }
            else {
                if(arr[i]<=init) {
                    marked[i]=1;
                    flag=1;
                    lastNum=arr[i];
                }
            }

        } else {
            
            if(arr[i]<=init && arr[i]>=lastNum) {
                marked[i]=1;
                lastNum=arr[i];
            }
        }
    }

    string ans;
    fori(i, 0, n) {
        if(marked[i]) ans.pb('1');
        else ans.pb('0');
    }

    cout << ans << nl;
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