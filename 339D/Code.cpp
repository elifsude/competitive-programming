#include <bits/stdc++.h>
using namespace std;
#define benfero freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define mm ' '
#define nl '\n'
typedef unsigned long long int ull;
typedef long long int ll;
int ar[1000000];
int t[1000000];
int n, m, b;
void segmentri(int idx,int snr,int is){
    if(idx==snr){return;}
    if(is==0){
        for(int i=idx;i<=snr;i+=2){
            t[i/2] = t[i] | t[i+1];
        }
    }
    else{
        for(int i=idx;i<=snr;i+=2){
            t[i/2] = t[i] ^ t[i+1];
        }
    }
    segmentri(idx/2,snr/2,!is);
}
void update(int idx,int is){
    if(idx==1){return;}
    if(idx%2==0){
       if(is==0){
        t[idx/2]=t[idx] | t[idx+1];
       } 
       else{
        t[idx/2]=t[idx] ^ t[idx+1];
       } 
    }
    else{
        if(is==0){
            t[idx/2] = t[idx] | t[idx-1];
        }
        else{
            t[idx/2] = t[idx] ^ t[idx-1];
        }
    }
    update(idx/2,!is);
}

int main()
{
    //benfero
    int i;
    cin>>n>>m;
    b=pow(2,n);
    for(i=0;i<b;i++){
        cin>>ar[i];
        t[i+b]=ar[i];
    }
    segmentri(b,2*b-1,0);
    int a, y;
    for(i=0;i<m;i++){
        cin>>a>>y;
        t[a+b-1]=y;
        update(a+b-1,0);
        cout<<t[1]<<nl;
    }
    return 0;
}