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
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std; 

void solve() {
    int n; cin >> n;
    vi twoPow(32, 0);
    while(n--) {
        int choice, num; cin >> choice >> num;
        if(choice==1) {
            twoPow[num]++;
        }
        else {
            vi numDecompose(32, 0);
            ford(i, 31, 0) {
                if(num>=(1LL<<i)) {
                    numDecompose[i]++;
                    num -= (1LL<<i);
                }
            }
            int diff = 0;
            ford(i, 31, 0) {
                diff = max(numDecompose[i]+diff - twoPow[i], 0LL);
                diff *= 2;
            }
            if(diff) cout << "NO" << nl;
            else cout << "YES" << nl;
        }
    }
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