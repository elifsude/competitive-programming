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
#define fn _Find_next
#define ff _Find_first
bool de;
typedef long long int ll;
ll n, m;
map<int,bool>mapp[N];
bitset<N>bs;
void dfs(int node){
    bs[node]=0;
    for(int i=bs.ff();i<bs.size();i=bs.fn(i)){
        if(!mapp[min(node,i)][max(node,i)]){dfs(i);}
    }
}



int main()
{
    #ifdef DEBUG
    benfero
    de=1;
    #endif
    fast
    cin>>n>>m;
    int i, a, b;
    for(i=0;i<m;i++){
        cin>>a>>b;
        mapp[min(a,b)][max(a,b)]=1;
    }
    ll ans=-1;
    for(i=1;i<=n;i++){bs[i]=1;}
    for(int i=bs.ff();i<bs.size();i=bs.fn(i)){ 
        if(bs[i]){dfs(i);ans++;}
    }
    cout<<ans;
    
    return 0;
}