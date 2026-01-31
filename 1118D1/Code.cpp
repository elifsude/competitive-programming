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
    int n, k;
    cin>>n>>k;
    int i;
    int ar[n];
    for(i=0;i<n;i++){
        cin>>ar[i];
    }
    sort(ar,ar+n,greater<int>());
    int d;
    for(d=1;d<=n;d++){
        int sum=0;
        for(i=0;i<n;i++){
            sum+=max(0,ar[i]-i/d);
        }
        if(sum>=k){
            cout<<d<<nl;
            return 0;
        }
    }
    cout<<-1<<nl;
    return 0;
    
    return 0;
}