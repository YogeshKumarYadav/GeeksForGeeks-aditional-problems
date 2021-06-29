//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_map> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

long long int getsum(long long int n)
{   if(n == 0)
        return 0;
    return (n%10) + getsum(n/10);
}

int RulingPair(vector<int> arr, int n) 
{
    unordered_map<long long int, int> mp;
    int ans = -1;
    for(int i = 0; i < n; i++)
    {
        long long int sum = getsum(arr[i]);
        if(mp.find(sum) == mp.end())
            mp[sum] = arr[i];
        else
        {
            ans = max(ans, (mp.find(sum)->second + arr[i]));
            mp[sum] = max(mp[sum], arr[i]);
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
		int n;
		cin>>n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		cout << RulingPair(arr,n)<<"\n";
	}
	return 0; 
} 

  // } Driver Code Ends