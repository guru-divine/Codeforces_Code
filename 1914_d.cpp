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

void solve() {
    int n; cin >> n;
    vector<pii> A(n), B(n), C(n);
    fori(i, 0, n-1) {
        cin >> A[i].F;
        A[i].S = i;
    }
    fori(i, 0, n-1) {
        cin >> B[i].F;
        B[i].S = i;
    }
    fori(i, 0, n-1) {
        cin >> C[i].F;
        C[i].S = i;
    }
    sortd(A); sortd(B); sortd(C);
    int ans = 0;
    fori(i, 0, n-1) {
        int curVal1 = A[i].F, curVal2 = A[i].F;
        set<int> st1, st2;
        st1.insert(A[i].S), st2.insert(A[i].S);
        fori(j, 0, n-1) {
            if(st1.find(B[j].S)==st1.end()) {
                curVal1 += B[j].F;
                st1.insert(B[j].S);
                break;
            }
        }
        fori(j, 0, n-1) {
            if(st1.find(C[j].S)==st1.end()) {
                curVal1 += C[j].F;
                st1.insert(C[j].S);
                break;
            }
        }

        fori(j, 0, n-1) {
            if(st2.find(C[j].S)==st2.end()) {
                curVal2 += C[j].F;
                st2.insert(C[j].S);
                break;
            }
        }
        fori(j, 0, n-1) {
            if(st2.find(B[j].S)==st2.end()) {
                curVal2 += B[j].F;
                st2.insert(B[j].S);
                break;
            }
        }
        ans = max({ans, curVal1, curVal2});
    }
    cout << ans << nl;
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