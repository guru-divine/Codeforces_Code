//Author: DIVYA RAJ (aka guru_divine)
#include <bits/stdc++.h>
#define ll long long
#define int unsigned long long
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

void solve(vi &twoPow) {
    int l, r; cin >> l >> r;
    int ans = 0;
    auto it = upper_bound(all(twoPow), r);
    it--;
    int len = sz(twoPow);
    if(*it>l && *it<=r) {
        ans = (*it)^(*it-1);
    }
    else {
        vi mini(len, 0), maxi(len, 0);
        int i = len-1;
        while(l) {
            mini[i] = (l%2);
            i--, l/=2;
        }
        i = len-1;
        while(r) {
            maxi[i] = (r%2);
            i--, r/=2;
        }
        printS(mini);
        printS(maxi);
        bool flag=0, flag2=0;
        for(int i=0; i<len; ++i) {
            if(mini[i]!=maxi[i]) {
                flag=1;
            }
            else {
                if(flag2 && flag) mini[i] = !maxi[i];
                else if(!flag2 && mini[i]==0) flag2=1;
            }
        }
        for(int i=0; i<len; ++i) {
            ans += ((maxi[i]^mini[i])<<(len-i-1));
        }
        // cout << "aai" << nl;
    }

    cout << ans << nl;
}

signed main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vi twoPow;
    int num = 1;
    while(num<=1e18) {
        twoPow.pb(num);
        num*=2;
    }
    // printN(twoPow);
    int t=1;
    // cin >> t;
    while(t--) solve(twoPow);
    return 0;
}