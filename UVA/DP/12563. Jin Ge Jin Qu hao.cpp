#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 
#define int long long


int n, t;

int dp[55][55][10000];

int solve(vector<int> &ar, int pos, int cnt, int t){

    if(t<=0 || pos>n){
        if(cnt==0)return 0;
        else return INT_MIN;
    }
    if(cnt==0)return 0;

    if(dp[pos][cnt][t] != -1)return dp[pos][cnt][t];

    int res = solve(ar, pos+1, cnt-1, t-ar[pos]) + ar[pos];
    res = max(res, solve(ar, pos+1, cnt, t));

    return dp[pos][cnt][t] = res;
}

signed main() {
   FAST_IO;
   // start
   int tt;
   cin>>tt;
   int cas = 0;
   while (tt--) {
      cin>>n>>t;

      vector<int> ar(n+1);
      ar[0] = 678;
      int sum = ar[0];
      for(int i=1; i<n+1; i++){
        cin>>ar[i];
        sum += ar[i];
      }
      sort(all(ar));

      t = min(t, sum);


      sum = 0;
      int cnt = 0;
      for(int i=0; i<n+1; i++){
        if(sum<t){
            sum+=ar[i];
            cnt++;
        }
      }

      for(int i=0; i<n+3; i++){
        for(int j=0; j<cnt+3; j++){
            for(int k=0; k<t+3; k++){
                dp[i][j][k] = -1;
            }
        }
      }

      int res = solve(ar, 0, cnt, t);

      cout<<"Case "<<++cas<<": ";
      cout<<cnt<<" "<<res<<"\n";



      
   
   }



   return 0;
}
