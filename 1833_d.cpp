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
#define reverse(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

void solve() {
    int n; cin >> n;
    vi arr(n);
    int maxi=INT_MIN, idx=-1, flag=0;
    fori(i, 0, n) {
        cin >> arr[i];
        if(arr[i]>maxi) {
            maxi=arr[i];
            idx=i;
        }
    }
    if(n==1) {
        cout << "1" << nl;
        return;
    }

    if(idx==0) {
        fori(i, 0, n) {
            if(arr[i]==n-1) idx=i;
        }
        // fori(i, idx, n) {
        //     cout << arr[i] << " ";
        // }

        // fori(i, 0, idx) {
        //     cout << arr[i] << " ";
        // }
        // cout << nl;
        // return;
    }

    
    if(idx==n-1 && arr[0]>arr[n-2]) {
        cout << arr[idx] << " ";
        if(arr[0]>arr[n-2]) {
            fori(i, 0, n-1) cout << arr[i] << " ";
        }
        else ford(i, n-2, 0) cout << arr[i] << " ";
        cout << nl;
        return;
    }


    

    fori(i, idx, n) {
        cout << arr[i] << " ";
    }

    int it=idx-1;
    int cnt=0;
    if(arr[0]>arr[it]) {
        cout << arr[it] << " ";
        if(arr[0]>arr[it-1]) {
            fori(i, 0, it) cout << arr[i] << " ";
        }
        else {
            ford(i, it-1, 0) cout << arr[i] << " ";
        }
        cout << nl;
        return;
    }
    while(true) {
        if(arr[it]>arr[0]) {
            cout << arr[it] << " ";
            cnt++;
            it--;
        }
        else break;
    }
    // if(cnt==0 && idx!=n-1) cout << arr[it] << " ";
    // else cnt=1;
    fori(i, 0, it+1) {
        cout << arr[i] << " ";
    }
    cout << nl;



}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}