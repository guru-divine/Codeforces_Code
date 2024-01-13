//Author: guru_divine
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mod 1000000007
using namespace std;

void solve() {
    int n; cin >> n;
    vi arr(n), brr(n);
    int maxA=-1, maxB=-1, secmaxA, secmaxB;
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
        if(!i) {
            maxA = arr[i];
            secmaxA = arr[i];
        }
        if(arr[i]>=maxA) {
            secmaxA = maxA;
            maxA = arr[i];
        }
    }
    for(int i=0; i<n; ++i) {
        cin >> brr[i];
        if(!i) {
            maxB = brr[i];
            secmaxB = brr[i];
        }
        if(brr[i]>=maxB) {
            secmaxB = maxB;
            maxB = brr[i];
        }
    }
    if(maxA==arr[n-1] && maxB==brr[n-1]) cout << "YES" << nl;

    else if(maxA==arr[n-1] && maxA>=maxB) {
        if(brr[n-1]>=secmaxA) cout << "YES" << nl;
        else {
            for(int i=0; i<n; ++i) {
                if(brr[i]<=brr[n-1]) continue;
                else if(brr[i]>brr[n-1] && arr[i]<=brr[n-1]) continue;
                else {
                    cout << "NO" << nl;
                    return;
                }
            }
            cout << "YES" << nl;
        }
    }

    else if(maxB==brr[n-1] && maxB>=maxA) {
        if(arr[n-1]>=secmaxB) cout << "YES" << nl;
        else {
            for(int i=0; i<n; ++i) {
                if(arr[i]<=arr[n-1]) continue;
                else if(arr[i]>arr[n-1] && brr[i]<=arr[n-1]) continue;
                else {
                    cout << "NO" << nl;
                    return;
                }
            }
            cout << "YES" << nl;
        }
    }
    else {
        cout << "NO" << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}