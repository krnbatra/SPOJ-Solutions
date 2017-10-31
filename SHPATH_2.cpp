    #include <bits/stdc++.h>
    #define pb           push_back
    #define Mod          1000000007
    #define all(x)       x.begin(),x.end()
    #define sz(x)        ((int)x.size())
    #define gcd(a,b)     __gcd(a,b)
    #define loop(i,n)    for((i)=0;(i)<(n);(i)++)
    #define loopr(i,a,b) for(i=(a);i<=(b);i++)
    #define sf(n)        scanf("%d", &n)
    #define sf2(a,b)     scanf("%d %d", &a, &b)
    #define sl(n)        scanf("%lld",&n)
    #define prl(n)       printf("%d\n",n)
    #define prs(n)       printf("%d ",n)
    #define prll(n)      printf("%lld\n",n)
    #define prsl(n)      printf("%lld ",n)
    #define ios          ios_base::sync_with_stdio(false)
    #define fillu(arr,a) memset(arr,(a),sizeof(arr))
    using namespace std;
    typedef long long int ll;
    ll power(ll x, ll y){ll t;if( y == 0)return 1;t=power(x,y/2);return (y%2==0)?t*t:x*t*t;}
    ll powm(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
    typedef vector<int> vi;
    typedef vector<ll> vl;
    typedef map<int,int> mi;
    typedef pair<int,int> pii;


int dist[10005];
int vis[10005];
vector<pair<int,int> > m[10005];

int main()
{
    ios;
 int i,j,k,l,v,z,t,e,a,b,c,x,y,w;
 cin>>t;
 while(t--)
 {

     unordered_map<string,int> strloc;
     cin>>v;
     string str[v+100];

     loop(l,v)
     {
         cin>>str[l];
         strloc[str[l]]=l;
         cin>>e;
         loop(i,e)
         {
             cin>>z>>w;
             z--;
             m[l].pb(make_pair(z,w));
         }
     }
     int n;
     cin>>n;
     loop(k,n)
     {
         string str1,str2;
         cin>>str1;
         cin>>str2;
         int s1=strloc[str1];
         int s2=strloc[str2];
         loop(i,10004) dist[i]=INT_MAX/2;
         fillu(vis,0);
         dist[s1]=0;
         multiset<pair<int,int>> ch;
         ch.insert({0,s1});
         while(!ch.empty())
         {
             pii pa = *ch.begin();
             int wght = pa.first;
             int vert = pa.second;
             ch.erase(ch.begin());
             if(vis[vert]==1)
                continue;
             vis[vert]=1;
             loop(i,m[vert].size())
             {
                 pii p = m[vert][i];
                 int v1 = p.first;
                 int d1 = p.second;
                // cout<<" d1 "<< d1+1 <<" dist[vert] "<<dist[vert]<<" dist[v1] "<<dist[v1]<<" v1 "<<v1+1<<endl;
                 if(d1+dist[vert]<dist[v1])
                 {
                     dist[v1]=d1+dist[vert];

                     ch.insert({dist[v1],v1});
                 }
             }
         }

         prl(dist[s2]);
         
     }
     loop(i,10005)
    m[i].erase(m[i].begin(),m[i].end());
 }
 return 0;
}
