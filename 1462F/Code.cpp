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
int main()
{
    #ifdef DEBUG
    benfero
    de=1;
    #endif
    fast
    int q;
    cin>>q;
    while(q--){
        int n, i, t, l, r, ans=1e9;
        vector<pair<int,int> >v;
        vector<int>R,L;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>l>>r;
            v.pb(mp(l,r));
            R.pb(r);
            L.pb(l);
        }
        sort(R.begin(),R.end());
        sort(L.begin(),L.end());
        for(i=0;i<v.size();i++){
            l=v[i].first; r=v[i].second;
            t=(lower_bound(R.begin(),R.end(),l)-R.begin()) +n-(upper_bound(L.begin(),L.end(),r)-L.begin());
            ans=min(ans,t);
        }
        cout<<ans<<endl;
    }

    
    return 0;
}