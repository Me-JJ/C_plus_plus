#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,l;
        cin>>n>>l;
        vector<vector<int> >count(l,vector<int>(2,0));
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            for(int j=0;j<l;j++)
            {
                int bit=((x>>j)&1);
                count[j][bit]+=1; 
            }
        }
        int y=0;
        for(int i=0;i<l;i++)
        {
            if(count[i][1]>count[i][0])
            y+=1<<i;
        }
        cout<<y<<endl;
    }
    return 0;
}