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

void solve(vi &seive) {
    int a, b; cin >> a >> b;
    int diff = b-a;
    if(diff==1) {
        cout << "-1" << nl; return;
    }
    else if(b%a==0 && a!=1) {
        cout << "0" << nl; return;
    }

    //find min k s.t gcd(a+k, b-a)>1
    //a prime factor of (b-a) also divides a+k
    int num = b-a, ans = 1e9;
    while(num!=1) {
        int factor = seive[num];
        ans = min(ans, ((a+factor-1)/factor)*factor - a);
        while(num%factor==0) num /=factor;
    }
    cout << ans << nl;
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vi seive(1e7+5, 1);
    for(int i=2; i<sz(seive); ++i) {
        if(seive[i]==1) {
            seive[i] = i;
            for(int j=i*i; j<sz(seive); j+=i) {
                seive[j] = i;
            }
        }
    }

    int t=1;
    cin >> t;
    while(t--) solve(seive);
    return 0;
}