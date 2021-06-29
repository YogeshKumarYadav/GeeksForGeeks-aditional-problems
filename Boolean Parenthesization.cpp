// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int dp[202][202][2];
    int mod=1003;
    
    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        return boolexp(S,0,N-1,true);
    }
    

    int boolexp(string& str, int i, int j, bool istrue){
    
    if(dp[i][j][istrue]!=-1)
       return dp[i][j][istrue];
    
    
      if(i>j)
        return false;
      if(i==j)
        if(istrue)
            return dp[i][j][istrue] = str[i] == 'T';
        else
            return dp[i][j][istrue] = str[i] == 'F';  

    int ans=0;
    for(int k=i+1;k<j;k+=2){
        int lt,lf,rt,rf;
        lt=boolexp(str,i,k-1,true);
        lf=boolexp(str,i,k-1,false);
        rt=boolexp(str,k+1,j,true);
        rf=boolexp(str,k+1,j,false);
        
        if(str[k] == '|')
            if(istrue == true)
                ans = ans + lt*rt + lf*rt + lt*rf;
            else
                ans = ans + lf*rf;

        else if(str[k] == '&')
            if(istrue == true)
                ans = ans + lt*rt;
            else
                ans = ans + lf*rf + lf*rt + lt*rf;

        else if(str[k] == '^')
            if(istrue == true)
                ans = ans + lt*rf + lf*rt;
            else
                ans = ans + lt*rt + lf*rf;
    }    
    return dp[i][j][istrue]=ans%mod; 
}
    
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends