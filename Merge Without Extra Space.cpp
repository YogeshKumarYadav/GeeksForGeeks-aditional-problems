// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            
            long long int temp,i=n-1,j=0;
	        while(i>=0 && j<m){
	            if(arr1[i]>arr2[j]){
	                temp=arr1[i];
	                arr1[i]=arr2[j];
	                arr2[j]=temp;
	            }
	            i--;
	            j++;
	        }
            
            for (long long int gap = n/2; gap > 0; gap /= 2)
            {   for (long long int i= gap; i < n; i += 1)
                    {   temp = arr1[i];
                        long long int j;
                        for (j = i; j >= gap && arr1[j - gap] > temp; j -= gap)
                             arr1[j] = arr1[j - gap];
                        arr1[j] = temp;
                    }
            }
    
            for (long long int gap = m/2; gap > 0; gap /= 2)
            {   for (long long int i = gap; i < m; i += 1)
                {   temp = arr2[i];
                    long long int j;
                    for (j = i; j >= gap && arr2[j - gap] > temp; j -= gap)
                        arr2[j] = arr2[j - gap];
                    arr2[j] = temp;
                }
            }
            
        } 
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends