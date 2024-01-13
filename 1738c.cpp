#include<iostream>
#define ll long long
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        int cntOdd=0, cntEven=0;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
            if(a[i]%2==0) cntEven++;
            else cntOdd++;
        }
        if(cntOdd > cntEven) {
            cout << "Alice" << endl;
        }
        else {
            if(n%2==0 && cntEven%2==0 && cntOdd%2==0) {
                cout << "Alice" << endl;
            }
            else cout << "Bob" << endl;
        }
    }
    return 0;
}