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
    vi arr(n-1);
    for(int i=0; i<n-1; ++i) {
        cin >> arr[i];
    }
    if(n==1) {
        cout << arr[0] << " " << arr[0] << nl;
        return;
    }
    int inc=0, dec=0, j=0, idx;

    int k=0, flag=0;
    for(int i=0; i<n-2; ++i) {
        if(!i) {
            if(arr[i+1]>arr[i]) flag=1;
            else if(arr[i+1]<arr[i]) flag=0;
            k++;
        }
        else if(arr[i+1]>arr[i] && flag==0) {
            k++;
            flag=1;
        }
        else if(arr[i+1]<arr[i] && flag==1) {
            k++;
            flag=0;
        }


        if(arr[i+1]>arr[i] && !inc) {
            inc=1;
            if(j==1) {
                idx=i;
                inc=2;
            }
            j++;
        }
        else if(arr[i+1]<arr[i] && !dec) {
            dec=1;
            if(j==1) {
                idx=i;
                dec=2;
            }
            j++;
        }
    }
    if(inc==0 || dec==0) {
        if(inc==0) {
            arr.pb(0);
            for(auto it: arr) {
                cout << it << " ";
            }
            cout << nl;
            return;
        }
        else {
            cout << "0 ";
            for(auto it: arr) {
                cout << it << " ";
            }
            cout << nl;
            return;
        }
    }
    else {

        if(dec<inc) {
            
            arr.insert(arr.begin()+idx, 0);

            int idx=0;
            for(int i=n-2; i>=0; --i) {
                if(arr[i]==arr[i-1]) {
                    // arr[i] = arr[i+1];
                    idx=i;
                    break;
                }
            }
            if(k==3) arr[idx]=0;

            for(auto it: arr) {
                cout << it << " ";
            }
            // cout << "inc->dec";
            cout << nl;
            return;

            // for(int i=1; i<n-1; ++i) {
            //     if(arr[i]==arr[i-1]) {
            //         arr[i] = arr[i+1];
            //         break;
            //     }
            // }
            // arr.insert(arr.begin(), 0);
            // for(auto it: arr) {
            //     cout << it << " ";
            // }
            // cout << nl;
            // return;
        }
        else {
            // arr.insert(arr.begin()+idx+1, 0);
            // for(auto it: arr) {
            //     cout << it << " ";
            // }
            // cout << "dec->inc";
            // cout << nl;
            // int flag=0;
            int idx=0;
            for(int i=n-2; i>=0; --i) {
                if(arr[i]==arr[i-1]) {
                    arr[i] = arr[i+1];
                    idx=i;
                    break;
                }
            }
            if(k==3) arr.erase(arr.begin()+idx);
            arr.insert(arr.begin(), 0);
            for(auto it: arr) {
                cout << it << " ";
            }
            cout << nl;
            return;
            // return;
        }
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