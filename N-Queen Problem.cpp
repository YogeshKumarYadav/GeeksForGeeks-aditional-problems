// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<vector<int> > result;

    void solve(vector<vector<char>>& board, int row, int rowmask, int ldmask, int rdmask, int& ways)
    {   int n = board.size();
        int all_rows_filled = (1 << n) - 1;
        if (rowmask == all_rows_filled)
        {
            vector<int> v;
            for (int i = 0; i < board.size(); i++)
            {   for (int j = 0; j < board.size(); j++)
                {   if (board[i][j] == 'Q')
                        v.push_back(j + 1);
                }
            }
            result.push_back(v);
            return;
        }
 
        int safe= all_rows_filled & (~(rowmask | ldmask | rdmask));
        while(safe)
        {   int p = safe & (-safe);
            int col = (int)log2(p);
            board[row][col] = 'Q';
            solve(board, row + 1, rowmask | p, (ldmask | p) << 1, (rdmask | p) >> 1,  ways);
            safe = safe & (safe - 1);
            board[row][col] = ' ';
        }
        return;
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        int ways=0;
        vector<vector<char> > board;
        for (int i = 0; i < n; i++) {
            vector<char> tmp;
            for (int j = 0; j < n; j++)
            {
                tmp.push_back(' ');
            }   
            board.push_back(tmp);
        }
 
        int rowmask = 0, ldmask = 0, rdmask = 0;
        int row = 0;
 
        result.clear();
        solve(board, row, rowmask, ldmask, rdmask, ways);
        sort(result.begin(),result.end());
        return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends