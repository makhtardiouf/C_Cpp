//Author : Jatin Goyal
//codecracker4

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007  //NA
#define N 1111
#define ll long long int
#define dt int
#define all(c) c.begin(), c.end()
#define dcl(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(dt i=a;i<=(dt)(b);i++)
#define tr(container, it) for(vector<dt> ::iterator it= container.begin(); it!=container.end(); it++)
#define trp(container, it) for(vector<pair<dt,dt> >::iterator it = container.begin(); it!=container.end(); it++)
#define tra(container, it) for(typeof(container.begin()) it = container.begin(); it!=container.end(); it++)
#define cc1(a)cout<<#a<<": "<<a<<endl;
#define cc2(a,b)cout<<#a<<": "<<a<<" , "<<#b<<": "<<b<< endl;
#define cc3(a,b,c)cout<<#a<<": "<<a<<" , "<<#b<<": "<<b<<" , "<<#c<<": "<<c<<endl;
#define cc4(a,b,c,d)cout<<#a<<": "<<a<<" , "<<#b<<": "<<b<<" , "<<#c<<": "<<c<<" , "<<#d<<": "<<d<<endl;
#define pr pair<dt,dt>  //NA
#define mp(a,b) make_pair(a,b)
#define pb push_back  //NA
#define gc getchar  //NA
#define F first
#define S second
int t;
int main()
{
	freopen("B-large.in","r",stdin);
    freopen("##out.cpp","w",stdout);
	//ios_base::sync_with_stdio(0);
	cin>>t;
	rep(tes,1,t)
	{
	    ll ans=0,n,k,a[N],b[N],c[N],d[N];
	    map<ll,ll>ma,mb;
	    cout<<"Case #"<<tes<<": ";
	    cin>>n>>k;
	    rep(i,0,n-1) cin>>a[i];
	    rep(i,0,n-1) cin>>b[i];
	    rep(i,0,n-1) cin>>c[i];
	    rep(i,0,n-1) cin>>d[i];
	    rep(i,0,n-1) rep(j,0,n-1) ma[a[i]^b[j]]++;
	    rep(i,0,n-1) rep(j,0,n-1) mb[c[i]^d[j]]++;
	    for(map<ll,ll>::iterator it=ma.begin();it!=ma.end();it++)
        {
            ll cur=(it->F^k);
            if(mb.find(cur)!=mb.end())
            {
                ans+=((ll)it->S)*((ll)mb[cur]);
            }
        }
        cout<<ans<<endl;
        ma.clear();
        mb.clear();
	}
}
