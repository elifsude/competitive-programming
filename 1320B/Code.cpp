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
bool visit[N];
int dis[N];
typedef long long int ll;
int main()
{
    #ifdef DEBUG
    benfero
    de=1;
    #endif
    fast
    int n, m, i, a, b;
    cin>>n>>m;
    vector<int>v[n+1];
    vector<int>trs[n+1];
    for(i=0;i<m;i++){
        cin>>a>>b;
        v[a].pb(b);
        trs[b].pb(a);
    }
    int pp;
    cin>>pp;
    int path[pp];
    for(i=0;i<pp;i++){
        cin>>path[i];
    }
    queue<int>q;
    q.push(path[pp-1]);
    visit[path[pp-1]]=1;
    dis[path[pp-1]]=0;
    while(!q.empty()){
        int nd=q.front();
        q.pop();
        for(int i=0;i<trs[nd].size();i++){
            if(!visit[trs[nd][i]]){
                dis[trs[nd][i]]=dis[nd]+1;
                visit[trs[nd][i]]=1;
                q.push(trs[nd][i]);
            }
        }
    }
    
    int mn=0, mx=0;
    for(i=0;i<pp-1;i++){
        int cnt=0;

        for(int e=0;e<v[path[i]].size();e++){
            if(dis[path[i]]==dis[v[path[i]][e]]+1){cnt++;}
        }

        if(dis[path[i]]!=dis[path[i+1]]+1){
            //cout<<path[i]<<" --> "<<path[i+1]<<" disler "<<dis[path[i]]<<" "<<dis[path[i+1]]<<endl;
            mn++;mx++;}
       
        
        else if(cnt>1){mx++;}
    }   

    cout<<mn<<" "<<mx;
    
    return 0;
}