// elifsude 
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define benfero freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
#define mm ' '
#define nl '\n'
#define pb push_back
#define mp make_pair
#define debug if(de) cout
#define MOD 100000007
#define N 200005
bool de;
typedef long long int ll;
int n, k, m;
int ar[300005];
vector<int>v[300005];
pair<int,int > km[300005];
void dfs(int pr,int nd){
    if(ar[nd]==1){km[nd].first=1;}
    else if(ar[nd]==2){km[nd].second=1;}
    for(int i=0;i<v[nd].size();i++){
        if(v[nd][i]!=pr){
            dfs(nd,v[nd][i]);
            km[nd].first+=km[v[nd][i]].first;
            km[nd].second+=km[v[nd][i]].second;
        }
    }
}
int main()
{
    #ifdef DEBUG
    benfero
    de=1;
    #endif
    fast
    cin>>n;
    int i, a, b;
    for(i=1;i<=n;i++){
        cin>>ar[i];
        if(ar[i]==1){k++;}
        else if(ar[i]==2){m++;}
    }
    for(i=1;i<n;i++){
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0,1);
    int ans=0;
    for(i=1;i<=n;i++){
        //cout<<i<<" "<<km[i].first<<" "<<km[i].second<<endl;
        if(km[i].first==k && km[i].second==0){ans++;}
        else if(km[i].first==0 && km[i].second==m){ans++;}
    }
    cout<<ans<<endl;
    return 0;
}