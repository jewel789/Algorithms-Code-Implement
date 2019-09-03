#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii  pair<int,int>
#define endl "\n"
#define mx 9999999

vector<int>graph[200000];

vector< pii > bridge;

bool vist[200000];
stack<int> order;
int parent[200000],low[200000],discover[200000];


int disc_time=0;




void dfs(int current){
  
     vist[current]=true;
     discover[current]=disc_time+1;
     low[current]=disc_time+1;
     disc_time+=1;
     int child=0;
   
     for(int i=0;i<graph[current].size();i++){
    	  int element =graph[current][i];
  	  	if(!vist[element]){

                child+=1;
                parent[element]=current;
                dfs(element);
                low[current]=min(low[current],low[element]);
                
                if( low[element]>discover[current])
                       bridge.pb({current,element});//  store bridge
          }
         else if(parent[current]!=element) low[current]=min(low[current],discover[element]);

     }
  
 }


  int main(){
        int n,m,src;
        cin>>n>>m;
        for(int i=0;i<n;i++){
          int x,y;
          cin>>x>>y;
          graph[x].pb(y);
          graph[y].pb(x);

        }

        dfs(1);
      for(auto x:bridge){
         cout<<x.first<<" "<<x.second<<" ";
         cout<<endl;

      }
    

 }