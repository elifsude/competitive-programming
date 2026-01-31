#include <bits/stdc++.h>
using namespace std;
#define benfero freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define mm ' '
#define nl '\n'
#define MOD 100000007
#define N 200005
typedef long long int ll;
vector<int>v[N];
set<int>sa, sb;
bool visit[N];
int n, m ,a, b;
void dfs1(int node){
    visit[node]=1;
    int i;
    for(i=0;i<v[node].size();i++){
        if(!visit[v[node][i]] && v[node][i]!=b){
            sa.insert(v[node][i]);
            dfs1(v[node][i]);
        }
    }
}
void dfs2(int node){
    visit[node]=1;
    int i;
    for(i=0;i<v[node].size();i++){
        if(!visit[v[node][i]] && v[node][i]!=a){
            sb.insert(v[node][i]);
            dfs2(v[node][i]);
        }
    }
}
int main()
{
    //benfero
    int q;
    cin>>q;
    int i;
    int x, y;
    while(q--){
        cin>>n>>m>>a>>b;
        for(i=1;i<=n;i++){
            v[i].clear();
        }
        sa.clear();
        sb.clear();
        memset(visit,0,sizeof(visit));
        for(i=0;i<m;i++){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs1(a);
        memset(visit,0,sizeof(visit));
        dfs2(b);
        ll top=0;
        for(auto i: sa){
            if(sb.count(i)){
                top++;
            }
        }
        ll ans=0;
        ans=(sa.size()-top)*(sb.size()-top);
        cout<<ans<<endl;
    }

    return 0;
}