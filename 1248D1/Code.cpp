#include <bits/stdc++.h>
using namespace std;
#define benfero freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define mm ' '
#define nl '\n'
typedef unsigned long long int ull;
typedef long long int ll;
int ar[505];
int a[1015];
int n;
int solve(){
    int minx=1e9;
    int temp=0;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        temp+=ar[i];
        minx=min(temp,minx);
        a[505+temp]++;
    }
    return a[505+minx];
}
int main()
{
    //benfero
    cin>>n;
    int i;
    int ch=0;
    char t;
    for(i=1;i<=n;i++){
        cin>>t;
        ar[i]=(t=='('?1:-1);
        ch+=ar[i];
    }
    if(ch!=0){cout<<0<<nl<<1<<mm<<1<<nl; return 0;}
    int ansl=0;
    int ansr=0;
    int ans=0;
    for(i=1;i<=n;i++){
        for(int e=i+1;e<=n;e++){
            swap(ar[i],ar[e]);
            int res = solve();
            if(res>ans){
                ans=res;
                ansl=i;
                ansr=e;
            }
            swap(ar[i],ar[e]);
        }
    }
    cout<<ans<<endl<<ansl<<mm<<ansr;
    return 0;
}