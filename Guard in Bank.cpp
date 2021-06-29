// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 
vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N);


 // } Driver Code Ends
//User function Template for C++

vector<vector<int>> findDistance(vector<vector<char>>& matrix, int m, int n)
{
    vector<vector<int>> ans(m, vector<int>(n));
    queue<pair<int, int>> q;
    for (int i=0; i<m; i++)
    {   for (int j=0; j<n; j++)
        {   if(matrix[i][j] == 'W')
                ans[i][j] = -1;
            else if (matrix[i][j] == 'G')
            {   q.push({i, j});
                ans[i][j] = 0;
            }
            else
                ans[i][j] = INT_MAX;
        }
    }
    
    while(!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
       
        if(i+1 >= 0 && i+1 < m && j >= 0 && j < n && matrix[i+1][j] == 'O')
        {   if(ans[i+1][j] > ans[i][j] + 1)
            {   ans[i+1][j] = ans[i][j] + 1;
                q.push({i+1, j});
            }
        }
        if(i >= 0 && i < m && j+1 >= 0 && j+1 < n && matrix[i][j+1] == 'O')
        {   if(ans[i][j+1] > ans[i][j] + 1)
            {   ans[i][j+1] = ans[i][j] + 1;
                q.push({i, j+1});
            }
        }
        if(i-1 >= 0 && i-1 < m && j >= 0 && j < n && matrix[i-1][j] == 'O')
        {   if(ans[i-1][j] > ans[i][j] + 1)
            {   ans[i-1][j] = ans[i][j] + 1;
                q.push({i-1, j});
            }
        }
        if(i >= 0 && i < m && j-1 >= 0 && j-1 < n && matrix[i][j-1] == 'O')
        {   if(ans[i][j-1] > ans[i][j] + 1)
            {   ans[i][j-1] = ans[i][j] + 1;
                q.push({i, j-1});
            }
        }
    }
    for(int i=0; i<m; i++)
    {   for(int j=0; j<n; j++)
        {   if(ans[i][j] == INT_MAX)
            {   ans[i][j] = -1;
            }
        }
    }
    return ans;
}

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        result = findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0; 
} 

  // } Driver Code Ends