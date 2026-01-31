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
    string w[6]={"abc","acb","bac","bca","cab","cba"};
    string asd[12];
    int i;
    int n;
    cin>>n;
    string s, t;
    cin>>s>>t;
    int e;
    int d;
    int x=0;
    int y=0;
    for(i=0;i<6;i++){
        for(e=0;e<3;e++){
            for(d=0;d<n;d++){
                asd[y]+=(w[i][e]);
            }
        }
        y++;
        for(e=0;e<n;e++){
            asd[y]+=w[i];
        }
        y++;
    }
    bool cx=0;
    for(i=0;i<12;i++){
        cx=1;
        for(e=1;e<3*n;e++){
            string temp;
            temp.push_back(asd[i][e-1]);
            temp.push_back(asd[i][e]);
            if(temp==s || temp==t){cx=0;break;}
        }
        if(cx){
            cout<<"YES"<<nl;
            cout<<asd[i];
            break;
        }
    }
    return 0;
}