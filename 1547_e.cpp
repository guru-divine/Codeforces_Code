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

//graph
void approach1() {
    int n, k; cin >> n >> k;
    set<pii> st;
    vector<pii> arr;
    vi minTemp(n, 1e10);

    fori(i, 0, k) {
        int x; cin >> x;
        arr.pb({0, x-1});
    }
    fori(i, 0, k) {
        int temp; cin >> temp;
        arr[i].F = temp;
        st.insert(arr[i]);
        minTemp[arr[i].S] = arr[i].F;
    }


    while(!st.empty()) {
        auto it = *st.begin();
        int temp = it.F;
        int idx = it.S;
        st.erase(it);
        if(temp<=minTemp[idx]) {
            if(idx-1>=0 && temp+1<minTemp[idx-1]) {
                if(minTemp[idx-1]!=1e10) st.erase({minTemp[idx-1], idx-1});
                minTemp[idx-1] = temp+1;
                st.insert({minTemp[idx-1], idx-1});
            }
            if(idx+1<n && temp+1<minTemp[idx+1]) {
                if(minTemp[idx+1]!=1e10) st.erase({minTemp[idx+1], idx+1});
                minTemp[idx+1] = temp+1;
                st.insert({minTemp[idx+1], idx+1});
            }
        }
        
    }

    printS(minTemp);
}

//dp
void approach2() {
    int n, k; cin >> n >> k;
    vi left(n, 1e10);
    vi right(n, 1e10);

    vi arr;
    fori(i, 0, k) {
        int x; cin >> x;
        arr.pb(x-1);
    }
    fori(i, 0, k) {
        int temp; cin >> temp;
        left[arr[i]] = temp;
        right[arr[i]] = temp;
    }

    fori(i, 1, n) {
        left[i] = min(left[i], left[i-1]+1);
    }
    ford(i, n-2, 0) {
        right[i] = min(right[i], right[i+1]+1);
    }

    vi ans(n);
    fori(i, 0, n) ans[i] = min(left[i], right[i]);
    printS(ans);
}

void solve() {
    // approach1();
    approach2();
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