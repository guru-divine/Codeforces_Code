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
    int n; cin >> n;
    vi arr(n);
    set<int> st;
    bool flag=0;
    int idx=-1;
    fori(i, 0, n-1) {
        cin >> arr[i];
        if(i && arr[i]==arr[i-1] && !flag) {
            flag=1, idx=i;
        }
        st.insert(arr[i]);
    }
    vi ans(n, 1);
    if(st.size()==1) {
        cout << "1" << nl;
        printS(ans);
        return;
    }
    int distElem = 0;
    if(n%2==0) {
        fori(i, 0, n-1) {
            ans[i] = 1+(i%2);
        }
        distElem = 2;
    }
    else {
        if(flag) {
            distElem = 2;
            fori(i, 1, n-1) {
                if(ans[i-1]==1) ans[i] = 2;
                else ans[i] = 1;

                if(i==idx) ans[i] = ans[i-1]; 
            }
        }
        else {
            distElem = 2;
            fori(i, 0, n-1) {
                ans[i] = 1+(i%2);
            }
            if(arr[n-1]!=arr[0]) {
                ans[n-1] = 3, distElem++;
            }
        }
    }

    cout << distElem << nl;
    printS(ans);
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