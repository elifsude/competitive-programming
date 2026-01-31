#include <bits/stdc++.h>
using namespace std;
#define benfero freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define mm ' '
#define nl '\n'
typedef unsigned long long int ull;
typedef long long int ll;
ll ar[200005][2];
ll a[200005];
ll b[200005];
int main()
{
    //benfero
    int n, c;
    cin>>n>>c;
    int i;
    for(i=1;i<n;i++){
        cin>>a[i];
    }
    for(i=1;i<n;i++){
        cin>>b[i];
    }
    ar[1][0]=a[1];
    ar[1][1]=b[1]+c;
    for(i=2;i<n;i++){
        ar[i][0]=min(ar[i-1][0],ar[i-1][1])+a[i];
        ar[i][1]=min(ar[i-1][0]+c,ar[i-1][1])+b[i];
    }
    for(i=0;i<n;i++){
        cout<<min(ar[i][0],ar[i][1])<<mm;
    }

    
    return 0;
}