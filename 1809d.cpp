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
    string s; cin >> s;
    ll sum=0;
    int flag=0;
    // for(int i=1; i<s.size(); ++i) {
    //     if(s[i-1]>s[i] && flag==0) {
    //         flag=1;
    //         sum += 1e12;
    //     }
    //     else if(s[i]==0 && flag==1) {
    //         sum += (1e12)+1;
    //     }
    //     else if(s[i]==1 && flag==1) {
    //         flag=0;
    //     }
    // }
    // cout << sum << nl;
    int cnt1=0, cnt0=0;
    int n=s.size();
    for(int i=0; i<n; ++i) {
        if(s[i]==1) {
            cnt1++;
            i++;
            while(i<n) {
                if(s[i]==1) {
                    cnt1++;
                    i++;
                }
                else {
                    cnt0++;
                    i++;
                    while(i<n) {
                        if(s[i]==0) {
                            cnt0++;
                            i++;
                        }
                        else {
                            flag=1;
                            break;
                        }
                    }
                }
                if(flag==1) {
                    if(cnt1==cnt0 && cnt1==1) {
                        sum += 1e12;
                        cnt1=0;
                    }
                    else if(cnt1==cnt0) {
                        sum += (1e12)*cnt1;
                        cnt1=0;
                    }
                    else if(cnt1<cnt0) {

                    }
                    else {

                    }
                    flag=0;
                }

            }
        }
        // else {
        //     cnt0++;
        //     i++;
        //     while(i<n) {
        //         if(s[i]==1) {
        //             cnt0++;
        //             i++;
        //         }
        //         else break;
        //     }
        // }

//         if(cnt)
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