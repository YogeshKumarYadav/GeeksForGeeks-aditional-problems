#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b)
{   if(a.second==b.second)
        return a.first<b.first;
    return a.second>b.second;
}

int main()
 {
	//code
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	       
	    unordered_map <int,int> mp;    
	    for(int i=0;i<n;i++)
	        mp[arr[i]]++;
	    
	    vector<pair<int,int>> v(mp.begin(),mp.end());
	    sort(v.begin(),v.end(),cmp);
	    for(int i=0;i<v.size();i++)
	        while(v[i].second>0)
	        {   cout<<v[i].first<<" ";
	            v[i].second--;
	        }          
	    cout<<endl;     
	       
	}
	
	return 0;
}