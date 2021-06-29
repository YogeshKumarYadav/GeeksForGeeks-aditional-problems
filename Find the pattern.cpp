// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
    
    public:
    
    long long int mod=1000000007;
    
    vector<vector<long long int>> mult(vector<vector<long long int>> a, vector<vector<long long int>> b)
    {
        int k=2;
        vector<vector<long long int>> c(k+1,vector<long long int>(k+1));
        for(int i=1;i<=k;i++)
            for(int j=1;j<=k;j++)
                for(int l=1;l<=k;l++)
                    c[i][j]=(c[i][j]+a[i][l]*b[l][j])%mod;
        return c;            
    }
    
    vector<vector<long long int>> powe(vector<vector<long long int>> a, int p)
    {
        if(p==1)
            return a;
        if(p%2)
            return mult(a, powe(a,p-1));
        vector<vector<long long int>> b=powe(a,p/2);
        return mult(b,b);
    }
    
    long long int NthTerm(long long int N)
    {
        // Code here
        int k=2;
        vector<long long int> f(k+1);
        f[1]=1;
        f[2]=1;
        
        vector<vector<long long int>> t(k+1, vector<long long int>(k+1));
        t[1][1]=0;
        t[1][2]=1;
        t[2][1]=5;
        t[2][2]=2;
        
        if(N==1)
            return 1;
        t=powe(t,N-1);    
    
        long long int res=0;
        for(int i=1;i<=k;i++)
            res=(res+t[1][i]*f[i])%mod;
        return res;    
    
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NthTerm(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends