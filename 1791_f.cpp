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

int sumDig(int n) {
    int ans = 0;
    while(n) {
        ans += n%10;
        n/=10;
    }
    return ans;
}

void solve() {
    int n, q; cin >> n >> q;
    vi arr(n);
    set<int> st;
    fori(i, 0, n) {
        cin >> arr[i];
        if(arr[i]>9) st.insert(i);
    }

    while(q--) {
        int choice; cin >> choice;
        if(choice==1) {
            int l, r; cin >> l >> r;
            l--; r--;
            int val = l;

            while(!st.empty()) {
                auto it = st.lower_bound(val);
                if(it==st.end() || *it>r) break;
                arr[*it] = sumDig(arr[*it]);
                val = *it+1;
                if(arr[*it]<10) st.erase(it);
                
            }

        }
        else {
            int x; cin >> x;
            x--;
            cout << arr[x] << nl;
        }
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