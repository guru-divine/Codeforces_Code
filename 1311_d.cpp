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
    int a, b, c; cin >> a >> b >> c;
    vi ans(3);
    int totMin = 1e12;
    for(int i=1; i<=2*a; ++i) {
        int num1 = i;
        for(int j=1; j<=(1e4+100)/i; ++j) {
            int num2 = j*num1;
            int num3a = (c/num2)*num2, num3b = (c/num2 + 1)*num2;
            int curMin = abs(num1-a) + abs(b-num2) + min(abs(c-num3a), abs(c-num3b));
            if(curMin<totMin) {
                totMin = curMin;
                ans[0] = num1, ans[1] = num2;
                if(abs(c-num3a)<abs(c-num3b)) ans[2] = num3a;
                else ans[2] = num3b;
            }
            totMin = min(totMin, curMin);
        }
    }
    cout << totMin << nl;
    printS(ans);
}

signed main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}