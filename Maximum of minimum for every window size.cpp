// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {   
        stack<int>stkr;
        vector<int>minright(n);
        for(int i=n-1;i>=0;i--)
        {   while(!stkr.empty() && arr[stkr.top()]>=arr[i])
                stkr.pop();
            minright[i]=(stkr.empty()?n:stkr.top());
            stkr.push(i);
        }
        
        vector<int>minleft;
        stack<int>stkl;
        stkl.push(0);
        minleft.push_back(-1);
        for(int i=1;i<n;i++) 
        {   while(!stkl.empty() && arr[stkl.top()]>=arr[i])
               stkl.pop();
                
            minleft.push_back(stkl.empty()? -1: stkl.top());
            stkl.push(i);
        }
        
        vector<int>res(n+1);
        for(int i=0;i<n;i++)
        {   int len=((minright[i]-minleft[i])-1);
            res[len]=max(res[len],arr[i]); 
        }
        for(int i=n-1;i>=1;i--)
            res[i]=max(res[i],res[i+1]);
        
        res.erase(res.begin());
        return res;
    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends