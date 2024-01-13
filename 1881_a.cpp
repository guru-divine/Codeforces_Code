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
#define printN(arr) fori(i,0,arr.size()-1) {cout << arr[i] << nl;}
using namespace std; 

void solve() {
    int n, m; cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    string s1_new;
    vi twoPow(25, 1);
    fori(i, 1, 24) {
        twoPow[i] = twoPow[i-1]*2;
    } 
    fori(i, 0, 50) s1_new += s1;
    fori(i, 0, sz(s1_new)-sz(s2)) {
        string temp = s1_new.substr(i, sz(s2));
        if(temp==s2) {
            int idx = i+sz(s2);
            idx = (idx+sz(s1)-1)/sz(s1);
            idx = *lower_bound(all(twoPow), idx);
            // cout << idx << " ";
            int num = 1, cnt=0;
            while(idx!=1) {
                idx/=2;
                cnt++;
            }
            cout << cnt << nl;
            return;
        }
    }
    cout << "-1" << nl;
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