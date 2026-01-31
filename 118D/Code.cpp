#include <bits/stdc++.h>
using namespace std;
#define benfero freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define mm ' '
#define nl '\n'
typedef unsigned long long int ull;
typedef long long int ll;
int nb, ni, kb, ki;
int dp[105][105][11][11];
int MOD=100000000;
int solve(int n1, int n2, int k1, int k2){
    if(n1<0 || n2<0 || k1<0 || k2<0){return 0;}
    if(!n1 & !n2){return 1;}
    if(dp[n1][n2][k1][k2]!=-1){return dp[n1][n2][k1][k2]%MOD;}
    dp[n1][n2][k1][k2]=((solve(n1-1,n2,k1-1,ki)%MOD)+(solve(n1,n2-1,kb,k2-1)%MOD))%MOD;
    return dp[n1][n2][k1][k2]%MOD;
}
int main()
{
    //benfero
    cin>>nb>>ni>>kb>>ki;
    memset(dp,-1,sizeof(dp));
    ll a= solve(nb,ni,kb,ki);
    cout<<a<<endl;
    
    return 0;
}