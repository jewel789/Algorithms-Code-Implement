#include<bits/stdc++.h>
using  namespace std;
#define pii pair<int,int> 
#define pb push_back
#define endl "\n"
#define mx  9999999
vector<pair<int,pii > > v;
vector<int> dis;


int main(){

        int n,m,src;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int x,y,w;

            cin>>x>>y>>w;
            src=x;
            v.pb(make_pair(w,make_pair(x,y)));

        }

   for(int i=0;i<=n;i++) dis.pb(mx);
   cin>>src;

   dis[src]=0;

   for(int i=0;i<=n;i++){

       for(int j=0;j<v.size();j++){
            int x=v[j].second.first;
            int y=v[j].second.second;
            int w=v[j].first;

            dis[y]=min(dis[y],dis[x]+w);
       }
   }        

for(int i=1;i<=n;i++){
    if(i!=src) cout<<dis[i]<<" "<<endl;
}

    
}