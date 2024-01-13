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
    int a, b; cin >> a >> b;
    int ans = b-a;
    for(int b_new=b; b_new<=b+ans; ++b_new) {
        int not_match_idx_a = 30;
        while(not_match_idx_a!=-1) {
            if((a>>not_match_idx_a) & 1) {
                if((b_new>>not_match_idx_a) & 1) {}
                else break;
            }
            not_match_idx_a--;
        }
        if(not_match_idx_a==-1) ans = min(ans, b_new-b+1);
        else {
            int not_match_idx_b_new = not_match_idx_a;
            while(not_match_idx_b_new++) {
                if((b_new>>not_match_idx_b_new) & 1) {
                    if((a>>not_match_idx_b_new) & 1) {}
                    else break;
                } 
            }
            int a_new = (1<<not_match_idx_b_new);
            int bit = not_match_idx_b_new;
            while(bit<30) {
                if((a>>bit & 1)) a_new += (1<<bit);
                bit++;
            }
            ans = min(ans, b_new-b + a_new-a+1);
        }
    }
    cout << ans << nl;
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