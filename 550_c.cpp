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
    string s; cin >> s;
    int n = s.size();
    
    fori(i, 0, n) {
        int num = s[i]-'0';
        if(num%8==0) {
            cout << "YES" << nl << num << nl;
            return;
        }
    }

    fori(i, 0, n) {
        fori(j, i+1, n) {
            int num = 10*(s[i]-'0') + (s[j]-'0');
            if(num%8==0) {
                cout << "YES" << nl << num << nl;
                return;
            }
        }
    }

    fori(i, 0, n) {
        fori(j, i+1, n) {
            fori(k, j+1, n) {
                int num = 100*(s[i]-'0') + 10*(s[j]-'0') + (s[k]-'0');
                if(num%8==0) {
                    cout << "YES" << nl << num << nl;
                    return;
                }
            }
        }
    }
    cout << "NO" << nl;
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