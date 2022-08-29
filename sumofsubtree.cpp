#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
vector<int> g[N];
int subsum[N];
int even[N];
void dfs(int vertex, int par = 0)
{
    if(vertex%2==0) {even[vertex]++;}
    subsum[vertex]+=vertex;
    for(int child:g[vertex])
    {
        if(child==par) continue;
        dfs(child,vertex); 
        subsum[vertex]+=subsum[child];
        even[vertex]+=even[child];

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
    for(int i=1;i<=ver-5;i++)
    {
        fill(subsum,subsum+N,0);
        fill(even,even+N,0);

    dfs(i);
     cout<<"vertex\t\t"<<"subsum\t\t"<<"even_ct"<<endl;
    for(int i=1;i<=ver;i++)
    {
        cout<<i<<"\t\t"<<subsum[i]<<"\t\t"<<even[i]<<endl;
    }
    }
}