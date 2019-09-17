#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll bmd(ll a,ll p,ll m){
	  if(p==0) return 1;
	  if(p%(ll)2){
	  	return ((a%m)*bmd(a,p-1,m))%m;
	  }
	  else {
	  	 return ((bmd(a,p/(ll)2,m)%m)*(bmd(a,p/(ll)2,m)%m))%m;
	  }
}
int main(){
    ll p,a;
    
    while(true){
    	cin>>p>>a;
    	int u=1;
    	if(!p & !a) break;
    	for(ll i=3;i*i<=p;i+=2){
    		if(p%i==0 ||  p%2==0){
    			if(bmd(a,p,p)!=a) cout<<"no"<<"\n";
              	else cout<<"yes"<<"\n";
              	u=0;
              	break;
    		}
    	}
      if(u)	cout<<"no"<<"\n";
    }
     
}
