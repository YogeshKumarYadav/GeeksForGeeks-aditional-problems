// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:

		int min_operations(vector<int> nums){
		    // Code here
		    int n=nums.size();
		    vector<int> arr(n,1);
		    for(int i=1;i<n;i++)
		    {   for(int j=0;j<i;j++)
		        {  if(nums[i]>nums[j] and (nums[i]-nums[j])>=(i-j))
		           {     arr[i]=max(arr[i],arr[j]+1);
		           }   
		        }  
		    }
		    return n-*max_element(arr.begin(),arr.end());
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
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans  = ob.min_operations(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends