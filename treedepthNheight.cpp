#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
vector<int> g[N];
int depth[N];
int height[N];
void dfs(int vertex, int par = 0)
{

    for(int child:g[vertex])
    {
        if(child==par) continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex); 
        height[vertex]=max(height[vertex],height[child]+1);
    }
}
int main()
{
    int ver;
    cin >> ver;
    for (int i = 1; i <= ver - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
        cout<<"vertex\t\t"<<"height\t\t"<<"depth"<<endl;
    for(int i=1;i<=ver;i++)
    {
        cout<<i<<"\t\t"<<height[i]<<"\t\t"<<depth[i]<<endl;
    }

}
