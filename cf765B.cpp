#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
           cin>>v[i]; 
        }
        cout<<endl; 
        int ans=-1;
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            auto it=m.find(v[i]);
            if(it!=m.end())
            {
                ans=max(ans,n-(i-it->second));
            }
            m[v[i]]=i;
        }
        cout<<ans<<endl;
    
    }
    return 0;
}