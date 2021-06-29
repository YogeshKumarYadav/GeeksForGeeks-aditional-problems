// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
    
    void swap(vector<int> &nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size();
	    pair<int, int> index[n];
	    for(int i=0;i<n;i++)
	    {  	index[i].first = nums[i]; 
		    index[i].second = i; 
    	} 
    	sort(index,index+n);

	    vector<bool> b(n,false); 
	    int ans=0; 
	    for(int i=0;i<n;i++) 
	    {   if(b[i] || index[i].second==i) 
			    continue; 
		    int c=0; 
		    int j=i; 
		    while(!b[j]) 
		    {   b[j]=1; 
			    j=index[j].second; 
			    c++; 
		    } 
		    if(c>0) 
		       ans+=(c-1); 
	    } 
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends