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
    int n, k; cin >> n >> k;
    int k1=0, k2=0;
    vi both, alice, bob;
    
    fori(i, 0, n) {
        int time;
        bool fav1, fav2;
        cin >> time >> fav1 >> fav2;
        if(fav1 && fav2) {
            both.pb(time);
            k1++, k2++;
        }
        else if(fav1==1) {
            alice.pb(time);
            k1++;
        }
        else if(fav2==1) {
            bob.pb(time);
            k2++;
        }
    }
    if(k1<k || k2<k) {
        cout << "-1" << nl;
        return;
    }

    sorti(alice); sorti(bob); sorti(both);
    vi prefAlice(sz(alice));
    vi prefBob(sz(bob));
    vi prefBoth(sz(both));

    fori(i, 0, sz(prefAlice)) {
        prefAlice[i] = alice[i];
        if(i) prefAlice[i] += prefAlice[i-1];
    }
    fori(i, 0, sz(prefBob)) {
        prefBob[i] = bob[i];
        if(i) prefBob[i] += prefBob[i-1];
    }
    fori(i, 0, sz(prefBoth)) {
        prefBoth[i] = both[i];
        if(i) prefBoth[i] += prefBoth[i-1];
    }

    int minTime = 1e18;
    int bothSize = sz(both);

    for(int i=0; i<=min(k, bothSize); ++i) {
        int left = k-i;
        if(left>prefAlice.size() || left>prefBob.size()) continue;
        int curTime = 0;
        if(i>0) curTime += prefBoth[i-1];
        if(left>0) curTime += prefAlice[left-1] + prefBob[left-1];

        // cout << curTime << " ";
        minTime = min(minTime, curTime);
    }

    cout << minTime << nl;
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