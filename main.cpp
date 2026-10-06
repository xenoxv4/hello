#include<bits/stdc++.h>
using namespace std;
using ll =  long long ;
void count(vector<ll> & range, vector<long long> & disc, vector<long long> & a, vector<long long> & b, vector<long long> & prefix) {
    ll n = a.size();
    
    // Process each tea going to tasters i, i+1, ..., n-1
    for(ll i = 0; i < n; i++) {
        long long target = a[i]; 
        
        ll start = i;
        ll last = n - 1;
        ll full = i - 1; 
        
        while (start <= last) {
            ll mid = start + (last - start) / 2;
            
            // Amount of tea needed to fill EVERY taster from i to mid
            long long consumed = prefix[mid] - (i > 0 ? prefix[i-1] : 0);
            
            if (consumed <= target) {
                // We have enough tea to fill everyone up to mid. 
                // Record this and try to push further right.
                full = mid;
                start = mid + 1;
            } else {
                // Not enough tea, we need to restrict the range to the left.
                last = mid - 1;
            }
        }
        
        // 1. Give full capacity to tasters from i to full
        if (full >= i) {
            range[i]++;
            if (full + 1 < n) {
                range[full + 1]--;
            }
        }
        
        if (full + 1 < n) {
            long long full_consumed = 0;
            if (full >= i) {
                full_consumed = prefix[full] - (i > 0 ? prefix[i-1] : 0);
            }
            long long leftover = target - full_consumed;
            disc[full + 1] += leftover;
        }
    }
    
 
    long long curr = 0;
    for(ll i = 0; i < n; i++) {
        curr += range[i];
        disc[i] += curr * b[i];
    }
    
    for(long long x : disc) {
        cout << x << " ";
    }
    cout << '\n';
}
// void count(vector<ll> & range, vector<ll> & disc, vector<ll> & a, vector<ll> &b, vector<ll> & prefix){
//        //so i have to fill the c wiht the numbers that can i fill in it
//        ll n = a.size();
//        for(ll i = 0; i<n; i++){
//            ll target = a[i]; // so target is a[i] so
//            //now binary search on that
//            ll last = n-1;
//            ll start =  i;
//            ll full = i-1;
//            while(start<=last){
//                ll mid = start + (last - start)/2;

//                if(prefix[i] - prefix[mid]==target){ 
//                     ll l = mid, r = start;
//                     range[l]++;
//                     range[r+1]--;
//                     break;
//                }
//                if(prefix[i]- prefix[mid]>target){
                     
//                }
//                if(prefix[i]- prefix[mid]<target){
                     
//                }
//            }
//        }
//        //now from here i will get the numbers of ranges and the disc so now i will do the merging :
//        ll curr = 0;
//     for(ll i = 0; i<n; i++){
//         curr+=range[i];
//            disc[i]+= curr * b[i];
//     }
//     for(ll x : disc){
//          cout<<x<<" ";
//     }
//     cout<<'\n';
// }
void solve(){
     ll n;
     cin>>n;
     vector<ll>a(n), b(n), prefix(n);

     for(ll i = 0;i<n; i++) cin>>a[i];
     for(ll i = 0; i<n; i++) cin>> b[i];


     ll temp = 0;
     for(ll i = 0; i<n; i++){
        temp+=b[i];
        prefix[i] = temp;
     }
    vector<ll>range(n, 0); // for ranges 
    vector<ll>disc(n, 0); // for discreate value specif if (a[i])

    count(range, disc, a, b, prefix);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   
   ll tt;
   cin>>tt;
   while(tt--){
     solve();
   }






    return 0;
}