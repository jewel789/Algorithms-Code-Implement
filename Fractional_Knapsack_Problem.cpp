#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
 struct Item{
   int v;
   int w;
   float d;
} item[1000];
bool compare(Item i1, Item i2) {
   return (i1.d > i2.d);
}
float knapsack(Item items[], int sizeOfItems, int W) {
   int i, j, pos;
   Item mx, temp;
   float totalValue = 0, totalWeight = 0;
   for (i = 0; i < sizeOfItems; i++) {
      items[i].d = items[i].v / items[i].w;
   }
   sort(items, items+sizeOfItems, compare);
   for(i=0; i<sizeOfItems; i++) {
      if(totalWeight + items[i].w<= W) {
         totalValue += items[i].v ;
         totalWeight += items[i].w;
      } else {
         int wt = W-totalWeight;
         totalValue += (wt * items[i].d);
         totalWeight += wt;
         break;
      }
   }
   cout << "total weight in bag " << totalWeight<<endl;
   return totalValue;
}
int main() {
   int n,W;
   cin>>n;
   for(int i=0;i<n;i++){
    cin>>item[i].v>>item[i].w;
   }

   cin >> W;
   float mxVal = knapsack(item, n, W);
   cout << "Max value for "<< W <<" weight is "<< mxVal;
}
