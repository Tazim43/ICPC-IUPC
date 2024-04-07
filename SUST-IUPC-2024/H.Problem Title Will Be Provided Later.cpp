#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

#define int long long

template <typename T>
class SparseTable
{
public:
    vector<T> lg, two;
    vector<vector<T>> st;
    void build(vector<int> &aa, int state)
    {
        int n = (int)aa.size();
        lg.resize(n + 1);
        lg[0] = lg[1] = 0;
        for (int ii = 2; ii <= n; ++ii)
            lg[ii] = lg[ii / 2] + 1;
        two.resize(lg[n] + 1);
        for (int ii = two[0] = 1; ii <= lg[n]; ++ii)
            two[ii] = two[ii - 1] * 2;
        st.resize(n, vector<T>(lg[n] + 1));
        for (int ii = 0; ii < n; ii++)
            st[ii][0] = aa[ii];
        for (int jj = 1; jj <= lg[n]; jj++)
            for (int ii = 0; ii + two[jj] <= n; ii++)
            {
                T x = st[ii][jj - 1];
                T y = st[ii + two[jj - 1]][jj - 1];
                st[ii][jj] = state ? max(x, y) : min(x, y);
            };
    }
    T query(int L, int R, int state)
    {
        int jj = lg[(R - L + 1)];
        T x = st[L][jj];
        T y = st[R - two[jj] + 1][jj];
        return state ? max(x, y) : min(x, y);
    }
};



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
		vector<int> pre_kadane(n, 0), suf_kadane(n, 0);
		int cur = 0;
		for(int i=0; i<n; i++){
			cur = max(cur+ar[i], 0LL);
			pre_kadane[i] = cur;
		}
		cur = 0;

		for(int i=n-1; i>=0; i--){
			cur = max(cur+ar[i], 0LL);
			suf_kadane[i] = cur;
		}

		int res = 0;

		// for positive
		for(int i=0; i<n; i++){
			int a = 0;
			if(i+1<n) a+= suf_kadane[i+1];
			int b = 0;
			if(i-1>=0)b += pre_kadane[i-1];
			int tot = a + b + ar[i];
			tot *= ar[i];
			res = max(res, tot);
		}

		// for negative

		SparseTable<int> ST;
		ST.build(ar, 1);

		vector<int> psum(n+1, 0);
		for(int i=0; i<n; i++){
			psum[i+1] = psum[i] + ar[i];
		}

		for(int i=0; i<n; i++){
			int L = i, R = i;
			
			int lo = i, hi = n-1; 
			while (hi-lo>1)
			{
				int mid = (hi+lo)/2;
				if(ST.query(i, mid, 1)==ar[i])lo = mid;
				else hi = mid-1;
			}
			if(ST.query(i, hi, 1)==ar[i])R =  hi;
			else R = lo;

			lo = 0, hi = i;
			while (hi-lo>1)
			{
				int mid = (hi+lo)/2;
				if(ST.query(mid, i, 1)==ar[i]){
					hi = mid;
				}
				else lo = mid+1;
			}
			if(ST.query(lo, i, 1)==ar[i])L = lo;
			else L = hi;

			int sum = psum[R+1] - psum[L];
			sum *= ar[i];

			res = max(res, sum);
			
		}
		cout<<res<<"\n";
	
	}



	return 0;
}
