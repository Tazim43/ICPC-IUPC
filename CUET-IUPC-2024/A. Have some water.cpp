#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 
#define int long long

int lcm(int a, int b){
	int x = (a*b)/__gcd(a, b);
	return x;
}


signed main() {
	FAST_IO;
	// start
	int t;
	cin>>t;
	read:
	while (t--) {

		int n;
		cin>>n;
		vector<int> ar(n);
		for(int i=0; i<n; i++){
			cin>>ar[i];
		}	
		int mx = 1e12;

		vector<int> dp(n, 0);
		map<int, int> pre_lc;

		for(int i=0; i<n; i++){
			
			int cur = ar[i];
			map<int, int> new_lc;
			new_lc[cur] = i;
			for(auto ii:pre_lc){
				int lc = lcm(ii.first, cur);
				if(lc>mx)continue;
				else{
					if(new_lc[lc])new_lc[lc] = min(new_lc[lc], ii.second);
					else new_lc[lc] = ii.second;
				}
			}
			pre_lc = new_lc;

			dp[i] = ar[i];
			if(i-1>=0)dp[i] += dp[i-1];

			for(auto ii:pre_lc){
				int aa = ii.first;
				if(ii.second>0)aa += dp[ii.second-1];
				dp[i] = min(dp[i], aa);
			}

		}

		cout<<dp[n-1]<<"\n";
	
	}



	return 0;
}
