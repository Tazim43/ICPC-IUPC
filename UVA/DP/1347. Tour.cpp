#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

int n;

long double dist(pair<int, int> &a, pair<int, int> &b){
	long double gap = (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
	long double res = sqrtl(gap);
	return res;
}

long double dp[1005][1005];

long double solve(vector<pair<int, int> > &ar, int p1, int p2){

	int nxt = max(p1, p2) + 1;
	if(nxt==n-1){
		long double aa = dist(ar[p1], ar[nxt]);
		long double bb = dist(ar[p2], ar[nxt]);
		return aa+bb;
	}
	if(dp[p1][p2]!=-1)return dp[p1][p2];

	long double aa = dist(ar[p2], ar[nxt]);
	long double res = solve(ar, p1, nxt) + aa;
	aa = dist(ar[p1], ar[nxt]);
	res = min(res, solve(ar, nxt, p2) + aa);

	return dp[p1][p2] = res;

}

int main() {
	FAST_IO;
	// start
	while (cin>>n)
	{
		for(int i=0; i<n+3; i++){
			for(int j=0; j<n+3; j++){
				dp[i][j] = -1;
			}
		}
		vector<pair<int, int> > ar(n);
		for(int i=0; i<n; i++){
			cin>>ar[i].first>>ar[i].second;
		}

		long double res = solve(ar, 0, 0);

		cout<<fixed<<setprecision(2)<< res<<endl;
	}
	



	return 0;
}
