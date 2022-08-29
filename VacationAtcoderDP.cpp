#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int a[N][4];
int dp[N][4];
int n;
int func(int d,int flag=0)
{
    if(d==n) return 0;
    if(dp[d][flag]!=-1) return dp[d][flag];
    int maxi=INT_MIN;
    if(flag==0)
    {
        maxi=max(maxi,a[d][1]+func(d+1,1));
        maxi=max(maxi,a[d][2]+func(d+1,2));
        maxi=max(maxi,a[d][3]+func(d+1,3));
    } 
    else if(flag==1)
    {
        maxi=max(maxi,a[d][2]+func(d+1,2));        
        maxi=max(maxi,a[d][3]+func(d+1,3));        
    }
    else if(flag==2)
    {
        maxi=max(maxi,a[d][1]+func(d+1,1));
        maxi=max(maxi,a[d][3]+func(d+1,3));
    }
    else
    {
        maxi=max(maxi,a[d][1]+func(d+1,1));
        maxi=max(maxi,a[d][2]+func(d+1,2));       
    }
    return dp[d][flag]=maxi;

}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=3;j++) 
        {
            cin>>a[i][j];
        }
    }
    cout<<func(0,0);

}