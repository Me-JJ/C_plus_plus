#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+7;
const LL mod=10e9+7;
vector<int>g[N];
int val[N];
int substree_sum[N];
void dfs(int ver,int p=0)
{
    substree_sum[ver]+=val[ver];
    for(auto child:g[ver])
    {
        if(child==p) continue;
        dfs(child,ver);
        substree_sum[ver]+=substree_sum[child];
    }

}
int main()
{
    int ver;
    cin>>ver;
    cin.ignore(1,ver);
    for(int i=1;i<=ver;i++)
    {
        cin>>val[i];
    }
    for(int i=1;i<=ver-1;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    LL ans=0;
    for(int i=2;i<=ver;i++)
    {
    LL part_1=substree_sum[i];
    LL part_2=substree_sum[1]-part_1;
    cout<<"part1--> "<<part_1<<"  part_2--> "<<part_2<<endl;
    ans=max(ans,((part_1)*1LL*(part_2)%mod));
    }
    cout<<ans<<endl;
    


}
