//Author: DIVYA RAJ
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define nl "\n"
#define pb push_back
#define popb pop_back
#define F first
#define S second
#define sz(arr) arr.size()
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define mapi map<int, int>
#define un_mapi unordered_map<int, int>
#define mod 1000000007
#define fori(i,a,b) for(int i=a; i<b; ++i)
#define ford(i,a,b) for(int i=a; i>=b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reversei(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

void solve() {
    string s; cin >> s;
    string rAlph, rNum, cAlph, cNum;
    bool flag=0, first=1;

    int i=0;
    while(i<sz(s)) {
        if(!flag) {
            while(i<sz(s) && s[i]>'9') {
                if(first) {
                    rAlph += s[i];
                }
                else cAlph += s[i];

                i++;
            }
            flag=1;
        } 
        else {
            while(i<sz(s) && s[i]<='9') {
                if(first) {
                    rNum += s[i];
                }
                else cNum += s[i];

                i++;
            }
            flag=0;
            first=0;
        }
    }

    vi arr(6, 1);
    fori(i, 1, 6) arr[i] = 26*arr[i-1];
    reversei(arr);

    if(cAlph.size()==0) {
        //Type -> BC23
        reversei(rAlph);

        int col=0;
        fori(i, 0, sz(rAlph)) {
            col += arr[6-i-1]*(rAlph[i]-'A'+1);
        }
        string ans="R" + rNum + "C" + to_string(col);

        cout << ans << nl;
    }
    else {
        //Type -> R23C55
        int col = stoi(cNum);
        string strTmp = "";
		while(col) {
			if(col % 26 == 0) {
                strTmp += 'Z';
                col /= 26; col--;
                continue;
            }
			strTmp += ((col % 26) + 'A' - 1);
			col /= 26;
		}
        reversei(strTmp);

        strTmp += rNum;
        cout << strTmp << nl;
    }
}

signed main() {
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}