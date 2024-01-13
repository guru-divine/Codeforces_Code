#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
int MOD = 1000000007;
int INF = 998244353;

int f(int n){
    int minm = 10, maxm = 0;
    while(n){
        int x = n%10;
        n /= 10;
        minm = min(minm, x);
        maxm = max(maxm, x);
    }
    return maxm - minm;
}

void solve(){
	int l, r; cin >> l >> r;
	string a, b; a = to_string(l), b = to_string(r);
	if(a.size() != b.size()){
	    string s = "";
        for(int i = 0; i<min(a.size(), b.size()); i++) s += '9';
        cout << s;
	}
	else if(l == r) cout << l;
	else{
		int num = 0, i = 0;
		while(i < a.size() && a[i] == b[i]){
			num = num*10 + (int)(a[i] - '0');
			i++;
		}
		int minm = 9, ans = l;
		for(int x = 0; x < 10; x++){
			for(int y = 0; y<10; y++){
				int z = num * 10 + x;
				for(int j = 0; j<a.size()-i-1; j++) z = z*10 + y;
				if(z<l || z>r) continue;
                int d = f(z);
                if(d < minm){
                    minm = d;
                    ans = z;
                }
			}
		}
		cout << ans;
	}

	return;
}

int32_t main(){
	FIO;
	
	int t = 1;
	cin >> t;
	for(int i = 1; i<=t; i++){
		// cout << "Case #" << i << ": ";
		solve();
		cout << "\n";
	}

	return 0;
}