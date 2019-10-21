
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

struct work{
  int start,finish;

}w[200];

bool com(work a,work b){
    return a.finish<b.finish;
}


int main(){

    int n,i,j,result[100],cnt;
    for(cin>>n,i=0;i<n;i++){
        cin>>w[i].start>>w[i].finish;
    }


    for(sort(w,w+n,com),cnt=1,j=0,i=1;i<n;i++){
          if(!j) cout<<w[j].start<<" "<<w[j].finish<<endl;
          if(w[i].start>=w[j].finish){
              cout<<w[i].start<<" "<<w[i].finish<<endl;
                j=i;
                cnt++;
          }

    }

    cout<<"maximum possible works "<<cnt;







}
