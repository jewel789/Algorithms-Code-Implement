#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii  pair<int,int>
#define endl "\n"
#define mx 99999999

vector<int>graph[200000];
bool vist[200000];
stack<int> order;

void dfs(int current){

  vist[current]=true;

  for(int i=0;i<graph[current].size();i++){
    	 int element =graph[current][i];
  		if(!vist[element]){
                dfs(element);
        }

     }
  order.push(current);

 }


  int main(){
        int n,m,src;
        cin>>n>>m;
        for(int i=0;i<n;i++){
          int x,y;
          cin>>x>>y;
          graph[x].pb(y);

        }
     for(int i=0;i<n;i++){
     	if(!vist[i])dfs(i);
     }


     while(!order.empty()){
     	int x=order.top();
     	order.pop();
     	cout<<x<<" ";// topolocial order
     }
 }