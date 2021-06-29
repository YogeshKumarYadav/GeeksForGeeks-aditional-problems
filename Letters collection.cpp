// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        // code here
        vector<int> sum;
        for (int i=0;i<q;++i)
        {   vector<int> query=queries[i];
            int h=query[0];
            int si=query[1];
            int sj=query[2];
            int ans=0;
            if(h==1)
            {   for(int k=-h;k<=h;++k)
                {   for(int t=-h;t<=h;++t)
                    {   int di=si+k;
                        int dj=sj+t;
                        if(di<0 || dj<0 || di>=n || dj>=m || (k==0 && t==0))
                            continue;
                        ans+=mat[di][dj];
                    }
                }
            }
            else
            {   for(int k=-h;k<=h;k+=h)
                {   if(k==0)
                        continue;
                    for(int t=-h;t<=h;++t)
                    {   int di=si+k;
                        int dj=sj+t;
                        if(di<0 || dj<0 || di>=n || dj>=m || (k==0 && t==0))
                            continue;
                        ans+=mat[di][dj];
                    }
                }
                for(int t=-h;t<=h;t+=h)
                {   for(int k=-1;k<=1;++k)
                    {   if(t==0)
                            continue;
                        int di=si+k;
                        int dj=sj+t;
                        if(di<0 || dj<0 || di>=n || dj>=m || (k==0 && t==0))
                            continue;
                        ans+=mat[di][dj];
                    }
                }
            }
            sum.push_back(ans);
        }

        return sum;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, q, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>q;
        vector<int> queries[q];
        for(int k = 0;k < q;k++){
            cin>>ty>>i>>j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }
        
        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}  // } Driver Code Ends