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

    int l1=-1,r1=-1, l2=-1, r2=-1, l11=-1, r11=-1, l22=-1, r22=-1;
    int flag1=0, flag2=0;

    int i=0;
    while(i<n-1) {
        if(s[i]=='A' && s[i+1]=='B') {
            if(!flag1) {
                flag1=1;
                l1=i; r1=i+1;
                l11=i; r11=i+1;
            } else {
                l11=i; r11=i+1;
            }
        }
        else if(s[i]=='B' && s[i+1]=='A') {
            if(!flag2) {
                flag2=1;
                l2=i; r2=i+1;
                l22=i; r22=i+1;
            } else {
                l22=i; r22=i+1;
            }

        }
        i++;
    }

    if((l22>r1 && r1!=-1) || (l11>r2 && r2!=-1)) {
        cout << "YES" << nl;
    }
    else cout << "NO" << nl;
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