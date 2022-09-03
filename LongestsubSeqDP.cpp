#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int a[N];
int dp[N];
int n;
int fun(int x)
{
    int ans=1;
    if(dp[x]!=-1) return dp[x];
    for(int i=0;i<x;i++ )
    {
        if(a[i]<a[x])
        ans=max(ans,fun(i)+1);
    }
    return dp[x]=ans;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ans=max(ans,fun(i));
    }
    for(int i=0;i<n;i++)
    {
        cout<<dp[i]<<endl;
    }
    cout<<ans;
    


}