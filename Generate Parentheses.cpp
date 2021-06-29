// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
void parenthesis(vector<string> &str, int open, int close, string br)
{
    if(open==0 && close==0)
    {   str.push_back(br);
        return;
    }   
    if(open!=0)
    {   string op1=br;
        op1.push_back('(');
        parenthesis(str,open-1,close,op1);
    }
    if(close>open)
    {   string op2=br;
        op2.push_back(')');
        parenthesis(str,open,close-1,op2);
    }
    return;
}

class Solution
{
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        vector<string> str;
        int open=n,close=n;
        string br="";
        parenthesis(str,open,close,br);
        return str;
        
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends