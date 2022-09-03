#include <bits/stdc++.h>
using namespace std;
const long long n=2e5+10;
long long wi[105], vi[105];
long long dp[105][n];
long long func(long long ind, long long tot_weight)
{
    if (ind < 0)
        return 0;
    if (tot_weight == 0)
        return 0;
    if(dp[ind][tot_weight]!=-1) return dp[ind][tot_weight];
    long long ans = func(ind - 1, tot_weight);

    if (tot_weight - wi[ind] >= 0)
        ans = max(ans, func(ind - 1, tot_weight - wi[ind]) + vi[ind]);

    return dp[ind][tot_weight]=ans;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    long long N, W;
    cin >> N >> W;
    for (long long i = 0; i < N; i++)
    {
        cin >> wi[i] >> vi[i];
    }
    cout << func(N - 1, W)<<endl;
}