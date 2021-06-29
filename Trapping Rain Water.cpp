// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        int maxl=0,maxr=0,l[n],r[n];
        for(int i=0;i<n;i++)
        {   l[i]=maxl;
            if(arr[i]>maxl)
                maxl=arr[i];
        }
        for(int i=n-1;i>=0;i--)
        {   r[i]=maxr;
            if(arr[i]>maxr)
                maxr=arr[i];
        }
        
        int sum=0;
        for(int i=1;i<n-1;i++)
            if(min(l[i],r[i])>arr[i])
                sum+=min(l[i],r[i])-arr[i];
        
      /*  for(int i=0;i<n;i++)
            cout<<l[i]<<"  ";
        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<r[i]<<"  ";
       */ 
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends