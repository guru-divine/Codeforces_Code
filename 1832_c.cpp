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
    int n; cin >> n;
    vi arr(n);

    fori(i, 0, n) {
        cin >> arr[i];
    }

    vi brr;
    brr.pb(arr[0]);

    fori(i, 1, n) {
        if(arr[i]!=arr[i-1]) brr.pb(arr[i]);
    }

    int len=brr.size();
    // printS(brr);
    if(len==1) {
        cout << "1" << nl;
        return;
    }
    ll cnt1=0, cnt2=0, cnt=0;
    int i=1;
    ll ans=0;
    while(i<len) {
        if(brr[i]>brr[i-1]) {
            i++;
            while(i<len) {
                if(brr[i]<brr[i-1]) {
                    // cnt++;
                    break;
                }
                cnt1++;
                i++;
            }
            ans+=2;
            cnt++;
        }
        else if(brr[i]<brr[i-1]) {
            i++;
            while(i<len) {
                if(brr[i]>brr[i-1]) {
                    // cnt++;
                    break;
                }
                cnt2++;
                i++;
            }
            ans+=2;
            cnt++;
        }
    }
    ans-=(cnt-1);

    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}