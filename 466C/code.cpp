#include <bits/stdc++.h>
using namespace std;
#define benfero freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define mm ' '
#define nl '\n'
#define MOD 1000007
typedef unsigned long long int ull;
typedef long long int ll;
int main()
{
    //benfero
    int n;
    cin>>n;
    int ar[n];
    int i;
    ll sum=0;
    for(i=0;i<n;i++){
        cin>>ar[i];
        sum+=ar[i];
    }
    if(sum%3!=0){cout<<0<<nl;return 0;}
    ll s=sum/3;
    ll cnt[n];
    memset(cnt,0,sizeof(cnt));
    sum=0;
    for(i=n-1;i>=0;i--){
        sum+=ar[i];
        if(sum==s){cnt[i]=1;}
    }
    for(i=n-2;i>=0;i--){
        cnt[i]+=cnt[i+1];
    }
    ll ans=0;
    sum=0;
    for(i=0;i<n-2;i++){
        sum+=ar[i];
        if(sum==s){
            ans+=cnt[i+2];
        }
    }
    cout<<ans<<endl; 

    
    return 0;
}