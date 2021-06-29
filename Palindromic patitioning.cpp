// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {   
        
    int n=str.length();
    int cut[n];
    bool palindrome[n][n];
    memset(palindrome, false, sizeof(palindrome));
    for (int i = 0; i < n; i++)
    {
        int minCut = i;
        for (int j = 0; j <= i; j++)
        {
            if (str[i] == str[j] && (i - j < 2 || palindrome[j + 1][i - 1]))
            {
                palindrome[j][i] = true;
                minCut = min(minCut, j == 0 ? 0 : (cut[j - 1] + 1));
            }
        }
        cut[i] = minCut;
    }
    return cut[n - 1];
    
        
        
        /*
        int n=str.length();
        bool t[n][n];
        for(int k=0;k<n;k++){
            for(int i=0,j=k;i<n;i++,j++){
                if(k==0)
                  t[i][j]=true;
                else if(k==1)
                  t[i][j]=str[i]==str[j];
                else{
                    if(str[i]==str[j] && t[i+1][j-1]==true)
                       t[i][j]=true;
                    else
                       t[i][j]=false;   
                }  
            }
        }

        int ans[n];
        ans[0]=0;
        for(int j=1;j<n;j++){
            if(t[0][j])
              ans[j]=0;
            else{
                int mans=INT_MAX;
                for(int i=j;i>=1;i--){
                    if(t[i][j])
                        mans=min(ans[i-1],mans);        
                }
                ans[j]=mans+1;
            }  
        }

        for(int l=0;l<n;l++)
        {   for(int p=0;p<str.length();p++)
                cout<<t[l][p]<<"  ";
            cout<<endl;  
        }
        cout<<endl<<endl; 
        for(int e=0;e<str.length();e++)
             cout<<ans[e]<<"  ";
        cout<<endl<<endl;

        return ans[n-1];
        */
        
}
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends