#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
int depth[N];
void dfs(int vertex,int par=-1)
{
    for(auto child:g[vertex])
    {
        if(child==par)continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
    }
}
int main()
{
    int ver;
    cin>>ver;
    for(int i=1;i<=ver-1;i++)
    {
        int v2,v1;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
    int maxdepth=-1;
    int max_d_node;
    for(int i=1;i<=ver-1;i++)
    {
        if(maxdepth<depth[i]) 
        {
            maxdepth=depth[i];
            max_d_node=i;
        }
    }
    cout<<"max deth node__ "<<max_d_node<<endl;
    fill(depth,depth+N,0);
    maxdepth=-1;
    dfs(max_d_node);
    for(int i=1;i<=ver-1;i++)
    {
        cout<<depth[i]<<" ";
        if(maxdepth<depth[i]) 
        {
            maxdepth=depth[i];
        }
    }
    cout<<endl;
    cout<<"diamter of tree is -->"<<maxdepth;


}
// 13
// 1 2
// 1 3
// 1 13
// 2 
// 5
// 5 6
// 5 7
// 5 8
// 8 12
// 3 4
// 4 9
// 4 10
// 10 11
