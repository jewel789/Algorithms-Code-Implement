#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int> 
#define mx 999999
#define endl "\n"


vector< int > graph[200000];
bool vist[23434];

vector<int> path,v[2000];

stack<int> singlepath;

int  source,destination  ,path_count;

void findpath(int current){//dfs

    if(current==destination){
      for(int i=0;i<path.size();i++)
            cout<<path[i]<<" ";//path printing 
       cout<<current<<endl;

      path_count++;

    }
   else {
       vist[current]=true;

       path.push_back(current);

       for(int i=0;i<graph[current].size();i++){
           int element=graph[current][i];
            if(!vist[element]){
               findpath(element);//dfs
          }
        }    
      vist[current]=false;
      path.pop_back();


    }
}


int main(){
      

      int  n,m;
      cin>>n>>m;
      for(int i=0;i<m; i++){
        int x,y,w;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
       
     }


   cin>>source>>destination;
   cout <<"paths between "<< source<<" to "<<destination << " are = \n";
   
   findpath(source);
 
   cout<<"total path are "<<path_count<<endl;
 }