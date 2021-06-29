// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
int repeatedStringMatch(string A, string B);


 // } Driver Code Ends
//User function Template for C++

bool check (string s, string b)
{
    int j;
    int n = s.length();
    int m = b.length();
    for(int i = 0; i <= (n - m); i++)
    {
        for(j = 0; j < m; j++)
        {
            if(b[j] != s[i + j])
                break;
        }
        if(j == m)
            return true;
    }
    return false;
}

int repeatedStringMatch (string a, string b){
    
    string s = a;
    int repeat = 1;
    while (s.length() < b.length())
    {   s = s + a;
        repeat++;
    }
    if (check (s, b))
        return repeat;
    if (check (s + a, b))
        return (repeat + 1);
    return -1;    
}

// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        cout<<repeatedStringMatch(A,B)<<"\n";
    }
    return 0;
}
  // } Driver Code Ends