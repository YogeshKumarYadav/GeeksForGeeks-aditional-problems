// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
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
                while(!stk.empty() && arr[stk.top()]>=arr[i])
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
                while(!stk.empty() && arr[stk.top()]>=arr[i])
                    stk.pop();
                r.push_back(stk.empty()?n-1:stk.top()-1);
                stk.push(i);
            }
        }
        reverse(r.begin(),r.end());
        /*
        for(int i=0;i<n;i++)
            cout<<l[i]<<"  ";
        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<r[i]<<"  ";
        */
        long long ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,arr[i]*(long long)(r[i]-l[i]+1));
        
        return ans;    
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends