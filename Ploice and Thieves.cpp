// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
int catchThieves(char arr[], int n, int k) ;

 // } Driver Code Ends
//User function Template for C++

int catchThieves(char arr[], int n, int k) 
{
    vector<int> t, p;
    for(int i=0; i<n; i++)
    {
        if(arr[i] == 'P')
            p.push_back(i);
        if(arr[i] == 'T')
            t.push_back(i);
    }
    int count = 0;
    int sizet = 0, sizep = 0;
    while(sizep < p.size() && sizet < t.size())
    {
        if(abs(p[sizep] - t[sizet]) <= k)
        {
            count++;
            sizet++;    
            sizep++;
        }
        else if(t[sizet] < p[sizep])
            sizet++;
        else
            sizep++;
    }
    return count;
}

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		cout<<catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 

  // } Driver Code Ends