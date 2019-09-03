#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii  pair<int,int>
#define endl "\n"
#define mx 9999999

vector<int>graph[200000];
vector<pii > articulation_point;
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
                articulation_point.pb({current,element});
                dfs(element);
                low[current]=min(low[current],low[element]);
                
                if((parent[current]==0 &&  child>1)|| (parent[current]!=0 && low[element]>=discover[current])) {
                     for(int i=articulation_point.size()-1;i;i--){
                      if( articulation_point[i]==make_pair(current,element)) break;
                       cout<<articulation_point[i].first<<" "<<articulation_point[i].second<<" ";
                       articulation_point.pop_back();
                     }
                     cout<<current<<" "<< element<< endl;
                     articulation_point.pop_back();
                }



             }
         else if(parent[current]!=element && discover[element]<low[current])
           low[current]=min(low[current],discover[element]),articulation_point.pb({current,element});

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
        cout<<endl;
      for(auto x:articulation_point){
       cout<<x.first<<" "<<x.second;

      }
    

 }