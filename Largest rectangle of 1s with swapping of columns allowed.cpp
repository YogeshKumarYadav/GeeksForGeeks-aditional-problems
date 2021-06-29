// { Driver Code Starts

#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Returns area of the largest rectangle of 1's
	int maxArea(vector<bool> mat[], int r, int c) {
	    // code here
	    vector<int> v;
	    vector<vector<int>> m;
	    for(int i=0;i<c;i++)
	        v.push_back(mat[0][i]);
	        
	    m.push_back(v);     
	    for(int i=1;i<r;i++)
	    {   for(int j=0;j<c;j++)
	        {
	            if(mat[i][j]==0)
	                v[j]=0;
	            else
	                v[j]+=mat[i][j];
	        }     
	        m.push_back(v);
	    } 
	    
	    for(int i=0;i<r;i++)
	        sort(m[i].begin(),m[i].end(),greater<int>());
	    /*    
	    for(int i=0;i<r;i++)
        {   for(int j=0;j<c;j++)
	            cout<<m[i][j]<<"  ";
	        cout<<endl;
	    }*/
	    int ans=0;
	    for(int i=0;i<r;i++)
	    {   for(int j=0;j<c;j++)
	        {   
	            ans=max(ans,m[i][j]*(j+1));   
	        }
	    }
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c, x;
        cin >> r >> c;
        vector<bool> mat[r];
        for (int i = 0; i < r; i++) {
            mat[i].assign(c, false);
            for (int j = 0; j < c; j++) {
                cin >> x;
                mat[i][j] = x;
            }
        }
        Solution ob;
        auto ans = ob.maxArea(mat, r, c);
        cout << ans << "\n";

    }
    return 0;
}
  // } Driver Code Ends