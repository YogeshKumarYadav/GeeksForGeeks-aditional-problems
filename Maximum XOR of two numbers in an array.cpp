// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    struct node
    {   node *left;
        node *right;
    };
    
    void insertbit(int n, node *root)
    {
        node *cur=root;
        for(int i=31;i>=0;i--)
        {
            int val=(n>>i)&1;
            if(val==0)
            {
                if(!cur->left)
                    cur->left=new node;
                cur=cur->left;    
            }
            else
            {
                if(!cur->right)
                    cur->right=new node;
                cur=cur->right;    
            }
        }
    }
    
    int max_xor(int arr[] , int n)
    {
        //code here
        node *root=new node;    
        for(int i=0;i<n;i++)
            insertbit(arr[i],root);
            
        int res=0;
        for(int i=0;i<n;i++)
        {
            int bitx=0;
            node *cur=root;
            for(int j=31;j>=0;j--)
            {
                int val=(arr[i]>>j)&1;
                if(val==0)
                {
                    if(cur->right)
                    {
                        int x=pow(2,j);
                        bitx+=x;
                        cur=cur->right;
                    }
                    else
                        cur=cur->left;
                }
                else
                {
                    if(cur->left)
                    {
                        int x=pow(2,j);
                        bitx+=x;
                        cur=cur->left;
                    }
                    else
                        cur=cur->right;
                }
                
            }
            res=max(res,bitx);
        }    
        return res;
    }
    
};


// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}


  // } Driver Code Ends