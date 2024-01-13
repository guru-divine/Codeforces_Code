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
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mapi map<int, int>
#define un_mapi unordered_map<int, int>
#define mod 1000000007
#define fori(i,a,b) for(int i=a; i<b; ++i)
#define forll(i,a,b) for(ll i=a; i<b; ++i)
#define ford(i,a,b) for(int i=a; i<b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

void solve() {
    ll n, q; cin >> n >> q;
    vll arr(n);
    fori(i, 0, n) {
        cin >> arr[i];
    }

    vll marked(n, 0);
    ll flag=0, cnt=-1;

    fori(i, 0, n-1) {
        if(flag==0) {
            if(arr[i]>=arr[i+1]) {
                cnt=1;
                flag=1;
            }
        }
        else {
            if(arr[i]>=arr[i+1]) {
                marked[i-1]=cnt;
                marked[i]=cnt+1;
                marked[i+1]=cnt+2;
                cnt++;
            }
            else flag=0;
        }
    }

    vll ans(n);
    cnt=0;
    // printS(marked);
    fori(i, 0, n) {
        if(marked[i]<3) cnt++;
        ans[i]=cnt;
    }

    // printS(ans);

    while(q--) {
        ll l, r; cin >> l >> r;
        if(r-l<2) {
            cout << r-l+1 << nl;
            return;
        }
        cout << ans[r-1]-ans[l-1]+1 << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}