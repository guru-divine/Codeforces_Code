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

void build(int idx, int l, int r, string &s, vector<vi> &seg) {
    if(l==r) {
        seg[idx][s[l]-'a']++;
        return;
    }
    int mid = (l+r)/2;
    build(2*idx, l, mid, s, seg);
    build(2*idx+1, mid+1, r, s, seg);
    fori(i, 0, 26) {
        seg[idx][i] = seg[2*idx][i]+seg[2*idx+1][i];
    }
}

void change(int idx, int l, int r, int pos, char &ch, string &s, vector<vi> &seg) {
    if(l>pos || r<pos) return;
    if(l==r) {
        s[l] = ch;
        fori(i, 0, 26) seg[idx][i]=0;
        seg[idx][ch-'a']++;
        return; 
    }
    int mid = (l+r)/2;
    change(2*idx, l, mid, pos, ch, s, seg);
    change(2*idx+1, mid+1, r, pos, ch, s, seg);
    fori(i, 0, 26) {
        seg[idx][i] = seg[2*idx][i]+seg[2*idx+1][i];
    }
}

void findDistinct(int idx, int l, int r, int lq, int rq, vector<vi> &seg, vi &temp) {
    if(r<lq || l>rq) return;
    if(lq<=l && r<=rq) {
        fori(i, 0, 26) {
            temp[i] += seg[idx][i];
        }
        return;
    }

    int mid = (l+r)/2;
    findDistinct(2*idx, l, mid, lq, rq, seg, temp);
    findDistinct(2*idx+1, mid+1, r, lq, rq, seg, temp);
}

void solve() {
    string s; cin >> s;
    int n = sz(s);
    vector<vi> seg(4*n+10, vi(26, 0));
    build(1, 0, n-1, s, seg);
    int q; cin >> q;
    while(q--) {
        
        int ch; cin >> ch;
        if(ch==1) {
            int pos; cin >> pos;
            pos--;
            char cr; cin >> cr;
            change(1, 0, n-1, pos, cr, s, seg);
            // cout << s << nl;
        }
        else {
            int l, r; cin >> l >> r;
            l--, r--;
            vi temp(26, 0);
            findDistinct(1, 0, n-1, l, r, seg, temp);
            int cnt = 0;
            fori(i, 0, 26) cnt += (temp[i]!=0);
            cout << cnt << nl;
        }

        // fori(i, 0, 26) cout << seg[1][i] << " ";
        // cout << nl;
    }
}

signed main() {
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}