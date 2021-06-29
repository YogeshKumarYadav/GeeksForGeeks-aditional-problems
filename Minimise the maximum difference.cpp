// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int minimizedMaxDiff(int arr[], int n, int k);

int main()
{
    int arr[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> arr[i];
        
        int k;
        cin>>k;
        
        cout<< minimizedMaxDiff(arr,n,k) << endl;
    }
    return 1;
}
// } Driver Code Ends


//User function Template for C++

int minimizedMaxDiff(int arr[], int n, int k)
{
    // code here
    
    int maxdif=INT_MIN;
    for(int i=0;i<n-1;i++)
        maxdif=max(maxdif,abs(arr[i]-arr[i+1]));
        
    if(maxdif==0)
        return 0;
    
    int l=1,r=maxdif,m,req;
    while(l<r)
    {
        m=l+(r-l)/2;
        req=0;
        for(int i=0;i<n-1;i++)
            req+=(abs(arr[i]-arr[i+1])-1)/m;
        
        if(req>k)
            l=m+1;
        else
            r=m;
    }
    return r;
}
