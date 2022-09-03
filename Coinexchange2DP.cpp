#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>a(N);
int dp[310][N];
int func(int ind,int amount)
{
    if(amount==0) return 1;
    int ways=0;
    if(ind>=0)
    {
        for(int i=0;i<=amount;i+=a[ind])
        {
            ways+=func(ind-1,amount-i);
        }
    }
    return ways;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n,amount;
    cin>>n>>amount;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k=func(n-1,amount);
    if (k==0 ? cout<<-1:cout<<k);
    cout<<endl; 

}