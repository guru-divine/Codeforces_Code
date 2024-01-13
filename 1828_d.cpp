//Author: DIVYA RAJ
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define popb pop_back
#define F first
#define S second
#define sz(arr) arr.size()
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mapi map<int, int>
#define un_mapi unordered_map<int, int>
#define mod 1000000007
#define fori(i,a,b) for(int i=a; i<b; ++i)
#define forll(i,a,b) for(ll i=a; i<b; ++i)
#define ford(i,a,b) for(int i=a; i<b; --i)
#define all(arr) arr.begin(), arr.end()
#define sorti(arr) sort(arr.begin(), arr.end())
#define sortd(arr) sort(arr.rbegin(), arr.rend())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define printS(arr) fori(i,0,arr.size()) {cout << arr[i] << " ";} {cout << nl;}
#define printN(arr) fori(i,0,arr.size()) {cout << arr[i] << nl;}
using namespace std;

int cnt;

// void merge(int *a, int l, int mid, int r) {
//     int n1 = mid-l+1;
//     int n2 = r-mid;
//     int L[n1], R[n2];
//     int i, j;
//     for(i=0; i<n1; ++i) {
//         L[i] = a[l+i];
//     }
//     for(i=0; i<n2; ++i) {
//         R[i] = a[mid+i];
//     }
//     // L[n1] = R[n2] = INT_MAX;
//     i = j = 0;
//     int k=l;
//     while(i<n1 && j<n2) {
//         if(L[i] >= R[j]) {
//             a[k] = R[j];
//             j++;
//             k++;
//         }
//         else {
//             a[k] = L[i];
//             i++;
//             k++;
//             cnt++;
//         }
//     }
//     while(i<n1) {
//         a[k] = L[i];
//         i++; k++;
//     }
//     while(j<n2) {
//         a[k] = R[j];
//         j++; k++;
//     }
// }

// void merge_sort(int *a, int l, int r) {
//     if(l==r) return;
//     int mid = (l+r)/2;
//     merge_sort(a, l,mid);
//     merge_sort(a, mid+1, r);
//     merge(a, l, mid , r);
// }

void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         cnt++;
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}

void solve() {
    cnt=0;

    int n; cin >> n;
    int arr[n];
    forll(i, 0, n) {
        cin >> arr[i];
    }

    forll(i, 2, n) {
      
    }

    mergeSort(arr, 0, n-1);

    forll(i, 0, n) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}