#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
struct Job{
        int id;
        int deadline;
        int profit;
}job[100];

bool com(Job a,Job b){
        return a.profit>b.profit;
}

int main(){
    int i,j,n,cnt=0,result[10000];
    bool slot[100000];
    for(cin>>n,i=0;i<n;i++){
        slot[i]=false;
        cin>>job[i].id>>job[i].deadline>>job[i].profit;
    }
    for(sort(job,job+n,com),i=0;i<n;i++){
        for( int j=min(n,job[i].deadline)-1;j>=0;j-- ){
              if(slot[j]==false){
                  result[j]=i;
                  slot[j]=true;
                  break;
              }
        }
    }
    for(int i=0;i<n;i++){
        if(slot[i])
            cout<<job[result[i]].id<<" ";

    }






}
