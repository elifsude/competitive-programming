#include <bits/stdc++.h>
using namespace std;
#define benfero freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define mm ' '
#define nl '\n'
#define MOD 100000007
#define N 200005
#define pb push_back
#define mp make_pair
int ar[N];
int dp[N];
int ans[N];
vector<int>v[N];
int n;
typedef long long int ll;
void dfs(int node, int pr){
    dp[node]=ar[node];
    int i;
    for(i=0;i<v[node].size();i++){
        int to=v[node][i];
        if(to!=pr){
        dfs(to,node);
        dp[node]+=max(0,dp[to]);}
    }
} 

void dfs2(int node, int pr){
    ans[node]=dp[node];
    int i;
    for(i=0;i<v[node].size();i++){
        int to=v[node][i];
        if(to==pr){continue;}
        dp[node]-=max(0,dp[to]);
        dp[to]+=max(0,dp[node]);
        dfs2(to,node);
        dp[to]-=max(0,dp[node]);
        dp[node]+=max(0,dp[to]);
    }
}

int main()
{
    //benfero
    cin>>n;
    int i;
    for(i=1;i<=n;i++){
        cin>>ar[i];
        if(ar[i]==0){ar[i]=-1;}
    }
    int a, b;
    for(i=1;i<n;i++){
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1,0);
    dfs2(1,0);
    for(i=1;i<=n;i++){
        cout<<ans[i]<<mm;
    }
    
    
    return 0;
}