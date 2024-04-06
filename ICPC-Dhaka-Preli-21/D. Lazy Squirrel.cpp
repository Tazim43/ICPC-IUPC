#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

const int N = 1e6+10;
vector<long long> gh[N], powers1(N, 1), powers2(N, 1);
long long n, tot = 0, res = 0, p1 = 127, p2 = 131, mod1 = 1e9+7, mod2 = 1e9+9;
string s;

void dfs(int node, int par = -1, long long fhash1=0, long long rhash1=0, long long fhash2 = 0, long long rhash2 = 0, int p = 1){
     tot++;
     long long ch = s[node-1];
     fhash1 = (fhash1 + 1LL * ch*powers1[p])%mod1;
     fhash2 = (fhash2 + 1LL * ch*powers2[p])%mod2;
     rhash1 = (1LL * (rhash1+ch)*p1 )%mod1;
     rhash2 = (1LL * (rhash2+ch)*p2) %mod2;
     if(fhash1==rhash1 && fhash2==rhash2)res++;
     for(auto child:gh[node]){
          if(child==par)continue;
          dfs(child, node, fhash1, rhash1, fhash2, rhash2, p+1);
     }
}


int main() {
   FAST_IO;
   // start
   for(int i=1; i<N; i++){
     powers1[i] = (1LL * powers1[i-1] * p1)%mod1;
     powers2[i] = (1LL * powers2[i-1] * p2)%mod2;
   }
   int t;
   cin>>t;
   int tt = 0;
   read:
   while (t--) {
      cin>>n;
      cin>>s;
      for(int i=0; i<n+3; i++){
          gh[i].clear();
      }
      for(int i=0; i<n-1; i++){
          int a, b;
          cin>>a>>b;
          gh[a].push_back(b);
          gh[b].push_back(a);
      }
      tot = 0;
      res = 0;
     dfs(1);

     cout<<"Case "<<++tt<<": ";
     int div = __gcd(res, tot);
     res/=div;
     tot/=div;
     cout<<res<<"/"<<tot<<"\n";
   
   }


   return 0;
}
