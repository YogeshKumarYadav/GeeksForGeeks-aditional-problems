// { Driver Code Starts

// driver code

#include <bits/stdc++.h>
using namespace std;

int min_sprinklers(int gallery[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        
        cout<< min_sprinklers(gallery,n) << endl;
    }
	return 1;
}
// } Driver Code Ends


//User function Template for C++

int min_sprinklers(int gallery[], int n)
{
    vector<pair<int, int>> arr;
    for(int i=0; i<n; i++)
        if(gallery[i] > -1)
            arr.push_back({i-gallery[i], i+gallery[i]});
            
    sort(arr.begin(), arr.end());
    
    int i = 0, target = 0, step = 0, count = 0;
    while(target < n)
    {
        if(i >= arr.size() || target < arr[i].first)
            return -1;
        step = arr[i].second;
        while(i+1 < arr.size() && target >= arr[i+1].first)
        {   i++;
            step = max(step, arr[i].second);
        }
        i++;
        count++;
        target = step + 1;
    }
    
    return count;    
}