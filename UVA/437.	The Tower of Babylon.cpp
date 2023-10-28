#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

struct node
{
   long long w, b, h;
};
int n;

long long dp[200];

long long solve(vector<node> &ar, int pos){
   if(dp[pos]!=-1)return dp[pos];
   long long res = 0;
   for(int i=0; i<n; i++){
      if(ar[i].w<ar[pos].w && ar[i].b<ar[pos].b){
         res =  max(res, solve(ar, i)+ar[i].h);
      }
   }
   return dp[pos] = res;
}


int main() {
   FAST_IO;
   // start
   int tt = 0;
   while (1)
   {
      cin>>n;
      if(n==0)break;
      vector<node> ar;
      for(int i=0; i<n; i++){
         int a, b, c;
         cin>>a>>b>>c;
         ar.push_back({a, b, c});
         ar.push_back({a, c, b});
         ar.push_back({b, a, c});
         ar.push_back({b, c, a});
         ar.push_back({c, a, b});
         ar.push_back({c, b, a});
      }

      n = ar.size();

      for(int i=0; i<n+5; i++){
         dp[i] = -1;
      }

      long long res = 0;
      for(int i=0; i<n; i++){
         res = max(res, solve(ar, i)+ar[i].h);
      }
      cout<<"Case "<<++tt<<": maximum height = ";
      cout<<res<<"\n";
      

   }
   



   return 0;
}
