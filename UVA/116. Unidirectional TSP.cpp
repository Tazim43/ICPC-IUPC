#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

#define int long long

int n, m;

int ar[15][105];

int dp[15][105];

pair<int, int> nxt[15][105];

int solve(int x=0, int y=0){

    if(y>=m)return 1e14;
    if(x>=n){
        x = 0;
    }
    if(x<0)x = n-1;
    if( y==m-1) return ar[x][y];

    if(dp[x][y] != -1)return dp[x][y];

    int res = ar[x][y] + solve(x+1, y+1);
    int _x = x+1;
    if(_x>=n)_x = 0;
    nxt[x][y] = {_x, y+1};

    int aa = solve(x-1, y+1) + ar[x][y];
    _x = x-1;
    if(_x<0)_x = n-1;
    if(aa<res){
        res = aa;
        nxt[x][y] = {_x, y+1};
    }
    else if(aa==res){
        if(nxt[x][y].first > _x)nxt[x][y] = {_x, y+1};
    }
    aa = solve(x, y+1) + ar[x][y];
    if(aa<res){
        res = aa;
        nxt[x][y] = {x, y+1};
    }
    else if(aa==res){
        if(nxt[x][y].first>x)nxt[x][y] = {x, y+1};
    }

    return dp[x][y] = res; 
}


signed main() {
   FAST_IO;
   // start

   while (cin>>n>>m)
   {
        
        for(int i=0; i<n+3; i++){
                for(int j=0; j<m+3; j++){
                    dp[i][j] = -1;
                }
        }

        for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    cin>>ar[i][j];
                }
        }

        int res = solve(0, 0);
        int x = 0;
        for(int i=1; i<n; i++){
            if(solve(i, 0)<res){
                res = solve(i, 0);
                x = i;
            }
        }

        int y = 0;
        while ( y!=m-1)
        {
                cout<<x+1<<" ";
                auto aa = nxt[x][y];
                x = aa.first;
                y = aa.second;
        }
        cout<<x+1<<"\n";
        

        cout<<res<<"\n"; 
   }



   return 0;
}

