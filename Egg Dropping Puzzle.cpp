// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        
        int t[n+1][k+1];
        for(int i=0;i<=n;i++)
        {  t[i][0]=0;
           t[i][1]=1;
        }
        for(int j=1;j<=k;j++)
        {  t[0][j]=0;
           t[1][j]=j;
        }
        
        for(int i=2;i<=n;i++)
        {  for(int j=2;j<=k;j++)
            {   int k=0,temp=INT_MIN,ans=INT_MAX;
                while(k<j)
                {  temp=max(t[i-1][k],t[i][j-k-1]);
                   k++;
                   ans=min(temp,ans);
                }
                t[i][j]=ans+1;
            }
        
        }
        return t[n][k];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends