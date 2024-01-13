#include<iostream>
#define ll long long
using namespace std;

int min(int a, int b) {
    if(a<b) return a;
    else return b;
}

int main() {
    int n;
    cin >> n;
    int grp[5]={0}, cnt=0;
    int s[n];
    for(int i=0; i<n; i++) {
        cin >> s[i];
        grp[s[i]]++;
    }
    cnt+=min(grp[1], grp[3]);
    grp[1] -= min(grp[1], grp[3]);
    grp[3] -= min(grp[1], grp[3]);
    cnt+= grp[2]/2;
    grp[2] = grp[2]%2;
    if(grp[1]!=0 && grp[2]!=0) {
        cnt++;
        grp[1]--;
        grp[2]--;
    }
    for(int i=0; i<5; i++) {
        cnt += grp[i];
    }
    cout << cnt << endl;

    return 0;
}