#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int> 
#define mx 999999
#define endl "\n"


vector< pii > graph[200000];

priority_queue <pii ,vector<pii> ,greater<pii > > q;

vector<int> path[20000],v[2000];

stack<int> singlepath;


int main(){
      

      int  n,m;
      cin>>n>>m;
      for(int i=0;i<m; i++){
        int x,y,w;
      	cin>>x>>y>>w;
      	graph[x].pb(make_pair(w,y));
        graph[y].pb(make_pair(w,x));
        mn=min(w,mn);
     }


   int src;
   cin>>src;
   vector<int> dis(mx,n);
   dis[0]=mx;
   dis[src]=0;
   q.push(make_pair(0,src));




   while(!q.empty()){
   		 int current = q.top().second;

         for(int i=0;i<graph[current].size();i++){
              pii element=graph[current][i];

              if(dis[element.second]>element.first+dis[current]){
                dis[element.second]= element.first+dis[current];
                q.push(element);

              }


          }

          q.pop();

	}

	for(int i=0;i<n;i++) cout<<dis[i]<<" distance of " <<i<<" \n";

     return 0;			
}