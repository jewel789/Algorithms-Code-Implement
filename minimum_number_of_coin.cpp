#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int n,m,coin[100];
int minCoins( int V) {
    if (V == 0) return 0;
    int res = INT_MAX;

   for (int i=0; i<m; i++) {
    	if (coin[i] <= V){
	     	int sub_res = minCoins(V-coin[i]);
	    	if (sub_res != INT_MAX && sub_res + 1 < res)
			res = sub_res + 1;
	   }
    }
   return res;
}

int main() {

	cin>>n>>m;
	for(int i=0;i<m;i++)
	  cin>>coin[i];

	cout << "Minimum coins required is "<< minCoins(n);
	return 0;
}
