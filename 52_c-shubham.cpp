#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define lc id<<1
#define rc id<<1|1
#define MAX_N 200100
const ll inf = 1e18;

struct node{
    ll lazy, mn;
    node(): mn(0), lazy(0) {}
    node(ll x): mn(x), lazy(0) {}
    friend node operator+(const node &a, const node &b)
    { return node(min(a.mn, b.mn)); }
} t[MAX_N<<2];
ll a[MAX_N], n, q;

void push(int id, int l, int r){
    if(t[id].lazy){
        t[id].mn += t[id].lazy;
        if(l!=r){
            t[lc].lazy += t[id].lazy;
            t[rc].lazy += t[id].lazy;
        }
        t[id].lazy = 0;
    }
}
void update(int id, int l, int r, int lq, int rq, ll val){
    push(id, l, r);
    if(r<lq || l>rq) return;
    if(lq<=l && r<=rq){
        t[id].lazy = val;
        push(id, l, r);
        return;
    }
    int mid=(l+r)>>1;
    update(lc, l, mid, lq, rq, val);
    update(rc, mid+1, r, lq, rq, val);
    t[id]=t[lc]+t[rc];
}
node query(int id, int l, int r, int lq, int rq){
    push(id, l, r);
    if(r<lq || l>rq) return node(inf);
    if(lq<=l && r<=rq) return t[id];
    int mid=(l+r)>>1;
    return query(lc, l, mid, lq, rq) + query(rc, mid+1, r, lq, rq);
}
void solve(){
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        update(1, 0, n-1, i, i, a[i]);
    }
    cin >> q;
    cin.ignore();
    while(q--){
        string s; getline(cin, s);
        istringstream iss(s);
        int l, r, x;
        if(count(s.begin(), s.end(), ' ')==1){
            iss >> l >> r;
            if(l<=r) cout << query(1, 0, n-1, l, r).mn << '\n';
            else cout << (query(1, 0, n-1, 0, r)+query(1, 0, n-1, l, n-1)).mn << '\n';
        }else{
            iss >> l >> r >> x;
            if(l<=r) update(1, 0, n-1, l, r, x);
            else update(1, 0, n-1, 0, r, x), update(1, 0, n-1, l, n-1, x);
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}