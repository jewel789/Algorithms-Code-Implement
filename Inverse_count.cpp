#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll powr(ll k){
   return 10*pow(10,k-1);
}
ll arr[1000000];
ll  merge(ll l,ll m, ll r){
   ll i,j,k,inverse=0;
   ll n1=m-l+1;
   ll n2=r-m;
   ll L[n1],R[n2];
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
   i=0,j=0,k=l;
   while( i<n1 && j<n2){
      if(L[i]<=R[j])arr[k++]=L[i++];
      else  arr[k++]=R[j++],inverse+=(n1-i);
     
   }
   while(i<n1){
      arr[k++]=L[i++];
   }
   while(j<n2) arr[k++]=R[j++];
   
   return inverse;
   
}
ll  merge_sort(ll l, ll r){
   ll inverse=0;
   if(l<r){
      ll m=(l+r)/2;
      inverse+=merge_sort(l,m);
      inverse+=merge_sort(m+1,r);
      inverse+=merge(l,m,r);
   }
   return inverse;
}
int main(){
   ll t, n,a[10000],s[10000],m[10000],cnt=0,flg=0;
   scanf("%lld",&t);
 //  getchar();
   while(t--){
      scanf("%lld",&n);
      //getchar();
      for(ll i=0;i<n;i++){
         scanf("%lld",&arr[i]);
      }
      getchar();
     
      
     printf("%lld\n", merge_sort(0,n-1));
  }
 
  
}
