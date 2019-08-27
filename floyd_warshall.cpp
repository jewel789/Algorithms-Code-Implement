#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int> 
#define mx 999999
#define endl "\n"


vector< int > graph[2000];

//priority_queue <pii ,vector<pii> ,greater<pii > > q;

vector<int> path[20000],v[2000],singlpath;

stack<int> singlepath;


int main(){
      
       int dis[24][30];
      int  n,m;
      cin>>n>>m;
      for(int i=0;i<n; i++)for(int j=0;j<n;j++) dis[i][j]=mx;
      for(int i=0;i<m; i++){
        int x,y,w;
      	cin>>x>>y>>w;
        dis[x][y]=w;
        dis[y][x]=w;
      	graph[x].pb(y);
        graph[y].pb(x);
     }


 
   for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
        	for(int k=1;k<n;k++){
        		dis[k][j]= min(dis[k][j],dis[k][i]+dis[i][j]);
        	}

        }

   }


  
	for(int i=1;i<n;i++) 
 		for(int j=1;j<n;j++)
          if(i!=j) cout<<i<<" "<<j<<"  "<<dis[i][j]<<endl;


   return 0;
}