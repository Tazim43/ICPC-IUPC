#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

const int N = 3e4+10;
int n;
vector<long long> cost(N);
vector<int> gh[N];

vector<bool> parity(N, 0);

void dfs(int node, int par = -1){
     for(auto child:gh[node]){
          if(child==par)continue;
          parity[child] = !parity[node];
          dfs(child, node);
     }
}

int main() {
   FAST_IO;
   // start
   int t;
   cin>>t;
   int tt = 0;
   read:
   while (t--) {
      
      cin>>n;
      for(int i=1; i<=n; i++){
          cin>>cost[i];
      }
      for(int i=1; i<=n+1; i++){
          gh[i].clear();
          parity[i] = 0;
      }

      for(int i=0; i<n-1; i++){
          int a, b;
          cin>>a>>b;
          gh[a].push_back(b);
          gh[b].push_back(a);
      }
      dfs(1);
      if(n==1){
          cout<<1<<"\n";
          continue;
      }
      long long zero = 0, one = 0;
      int cnt1 = 0, cnt2 = 0;
      for(int i=1; i<=n; i++){
          if(parity[i]){
               one+=cost[i];
               cnt1++;
          }
          else{
               zero+=cost[i];
               cnt2++;
          }
      }
      long long res = 1, mx = 0;
      for(int i=1; i<=n; i++){
          long long cur;
          if(parity[i]){
               cur = (cnt1-1)*cost[i]-(one-cost[i]);
               cur+= zero-(cost[i]*cnt2);
          }
          else{
               cur = (cnt2-1)*cost[i]-(zero-cost[i]);
               cur+=one-(cost[i]*cnt1);
          }
          if(cur>mx){
               res = i;
               mx = cur;
          }
      } 
      cout<<"Case "<<++tt<<": ";
      cout<<res<<"\n";
   
   }

   return 0;
}
