// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends

/*You are required to complete this method*/

class Solution{
  public:
    int area(vector<int> v, int n)
    {
        int ans=0;
        vector<int> l;
        vector<int> r;
        stack<int> stk;
        for(int i=0;i<n;i++)
        {
            if(stk.empty())
            {
                l.push_back(0);
                stk.push(i);
            }
            else
            {
                while(!stk.empty() && v[stk.top()]>=v[i])   
                    stk.pop();
                l.push_back(stk.empty()?0:stk.top()+1);    
                stk.push(i);
            }
        }
        while(!stk.empty())
            stk.pop();
        for(int i=n-1;i>=0;i--)
        {
            if(stk.empty())
            {
                r.push_back(n-1);
                stk.push(i);
            }
            else
            {
                while(!stk.empty() && v[stk.top()]>=v[i])
                    stk.pop();
                r.push_back(stk.empty()?n-1:stk.top()-1);    
                stk.push(i);
            }
        }
        reverse(r.begin(),r.end());
        for(int i=0;i<n;i++)
            ans=max(ans, v[i]*(r[i]-l[i]+1));
            
        return ans;
    }
  
    int maxArea(int mat[MAX][MAX], int n, int m) {
        // Your code here
        vector<int> v;
        stack<int> stk;
        int ans=0;
        for(int i=0;i<m;i++)
            v.push_back(mat[0][i]);
        ans=area(v,m);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                    v[j]+=mat[i][j];        
                else
                    v[j]=0;
                
            }
            ans=max(ans,area(v,m));
        }  
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends