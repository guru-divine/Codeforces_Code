//Author: DIVYA RAJ (aka guru_divine)
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define nl "\n"
#define pb push_back
#define F first
#define S second
#define sz(arr) (int)arr.size()
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
    vi arr(n+1), xori(n+1, 0);
    fori(i, 1, n+1) {
        cin >> arr[i];
        xori[i] = arr[i]^xori[i-1];
    }


    fori(i, 1, n+1) {
        int ans1 = xori[i];
        int ans2 = xori[n]^xori[i];
        if(ans1==ans2) {
            cout << "YES" << nl;
            return;
        }
    }
    fori(i, 1, n+1) {
        fori(j, i+1, n+1) {
            int ans1 = xori[i];
            int ans2 = xori[j]^xori[i];
            int ans3 = xori[n]^xori[j];
            if(ans1==ans2 && ans2==ans3) {
                cout << "YES" << nl;
                return;
            }
        }
    }

    cout << "NO" << nl;
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}