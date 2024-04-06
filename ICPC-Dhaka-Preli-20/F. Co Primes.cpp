#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

#define debug(x) cout<<#x<<" = ";_print(x); cout<<endl; /// Debug function
template<class T> void _print(T x) { cout << x; }
template<class T> void _print(vector<T>x) { cout << "[ ";for (T i : x)cout << i << " ";cout << "]"; }
template<class T> void _print(set<T>x) { cout << "[ ";for (T i : x)cout << i << " ";cout << "]"; }
template<class T, class V> void _print(pair<T, V>x) { cout << "{" << x.first << "," << x.second << "} "; }
template<class T, class V> void _print(map<T, V>x) { cout << "[ ";for (auto i : x)_print(i);cout << "]"; }
template<class T> void _print(multiset<T>x) { cout << "[ ";for (T i : x)cout << i << " ";cout << "]"; }

long long divisor(long long a, long long b, long long val){

   long long aa = a/val;
   aa*=val;
   if(aa<a)aa+=val;
   long long bb = b/val;
   bb*=val;
   long long res = 0;
   if(aa<=b && bb>=aa){
      res = (bb-aa)/val + 1;
   }
   return res;
   
}

const int N = 1e6+10;
vector<long long> is_prime(N, 1);
vector<long long> primes;

int main() {
   FAST_IO;
   // start
   is_prime[1] = 0;
   for(long long i=2; i*i<=N; i++){
      if(is_prime[i])
         for(long long j=i+i; j<N; j+=i)is_prime[j] = 0;
   }
   
   for(long long i=2; i<N; i++){
      if(is_prime[i]){
         primes.push_back(i);
      }
   }
   long long t, tt = 0;
   cin>>t;
   read:
   while (t--) {
      long long a,b , m;
      cin>>a>>b>>m;
      if(a==b){
         cout<<"Case "<<++tt<<": ";
         if(a==1)cout<<1<<"\n";
         else cout<<0<<"\n";
         goto read;
      }
      if(a>b)swap(a,b);
      long long gap = b-a;
      vector<long long> res;
      long long cur = gap;
      for(long long i=0; i<primes.size(); i++){
         if(cur<primes[i])break;
         if(cur%primes[i]==0){
            res.push_back(primes[i]);
            while (cur%primes[i]==0)
            {
               cur/=primes[i];
            }
         }
      }
      if(cur>1)res.push_back(cur);
      long long sz = res.size();
      // debug(res)
      long long nn = (1<<sz);
      // debug(nn)
      long long ans = 0;
      for(long long i=1; i<nn; i++){
         long long cnt = 0, rnd = 0;
         long long temp = i;
         long long val =1;
         while (temp>0)
         {
            if(temp%2){
               rnd++;
               val*=res[cnt];
            }
            temp/=2;
            cnt++;
         }
         if(rnd%2){
            ans+=divisor(a, a+m, val);
         }
         else ans-=divisor(a, a+m, val);

         
      }
      // debug(res)
      ans = max(m+1-ans, 0LL);
      cout<<"Case "<<++tt<<": ";
      cout<<ans<<"\n";
      
   
   }


   return 0;
}
