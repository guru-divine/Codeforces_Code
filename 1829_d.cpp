//Author: DIVYA RAJ
#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define pb push_back
#define popb pop_back
#define F first
#define S second
#define sz(arr) arr.size()
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define map map<int, int>
#define un_map unordered_map<int, int>
#define mod 1000000007
#define fori(i,a,b) for(int i=a; i<b; ++i)
#define forll(i,a,b) for(ll i=a; i<b; ++i)
#define ford(i,a,b) for(int i=a; i<b; --i)
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

void solve() {
    int n, target; cin >> n >> target;
    if(target==n) {
        cout << "YES" << nl;
        return;
    }

    set<int> st;

    int temp1=target*3;
    if(n==temp1) {
        cout << "YES" << nl;
        return;
    }
    if(temp1<n) st.insert(temp1);


    if(target%2==0) {
        int temp2=(target*3)/2;
        if(n==temp2) {
            cout << "YES" << nl;
            return;
        }
        if(temp2<n) st.insert(temp2);
    }
    
    while(!st.empty()) {
        for(auto it=st.begin(); it!=st.end(); ++it) {
            int num = *it;
            st.erase(num);

            int num1 = num*3;
            if(n==num1) {
                cout << "YES" << nl;
                return;
            }
            if(num1<n) st.insert(num1);

            // int num2 = (3*num)/2;
            if(num%2==0) {
                int num2=(num*3)/2;
                if(n==num2) {
                    cout << "YES" << nl;
                    return;
                }
                if(num2<n) st.insert(num2);
            }

            
        }
    }

    cout << "NO" << nl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}