#include <bits/stdc++.h>
using namespace std; 

void solve() {
    int n; cin >> n;
    string str; cin >> str;

    for(int x=1; x<=n; x++) {
        for(int y=1; y<=n; y++) {

            int num1=0, num2=0;
            int num3=0, num4=0;

            for(int i=0; i<n; ++i) {
                if(str[i]=='B') {
                    num2++;
                    if(num2==x) {
                        num4++;
                        if(num4==y && i==n-1) { cout << "B" << endl; return;}
                    }
                }
                else {
                    num1++;
                    if(num1==x) {
                        num3++;
                        if(num3==y && i==n-1) { cout << "A" << endl; return;}
                    }
                }
            }
        }
    }
    cout << "?" << endl;
    return;
}

int main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t=1; cin >> t;
    while(t--) solve();
    return 0;
}