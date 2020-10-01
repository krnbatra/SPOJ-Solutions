/************

   Author :- Profesor(Abhishek)
   2020-08-24-15.32.01
**********/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define fori(i,a,b) for(ll i=a;i<b;i++)
#define forr(i,a,b) for(ll i=a;i>=b;i--)
#define forit(it,x) for (auto it=(x).begin();it!=(x).end(); it++)
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sll set<ll>
#define vll vector<ll>
#define msl map<string,ll>
#define mll map<ll,ll>

const ll MAXN = (ll)1e7;
const ll big = (ll)1e9+7;

ll i, j, k;

vector<ll> phi(MAXN+1);
ll prime[MAXN+5];
int count_prime[MAXN+5];


void phi_1_to_n() {

    phi[0] = 0;
    phi[1] = 1;
    for ( i = 2; i <= MAXN; i++)
        phi[i] = i;

    for (i = 2; i <= MAXN; i++) {
        if (phi[i] == i) {
            for (j = i; j <= MAXN; j+=i)
                phi[j] -= phi[j] / i;
        }
    }

}

void sieve_of_erastothenes()
{
    prime[1]=0;
    for(i=2;i<=MAXN+2;i++)
    {
        prime[i]=1;
    }
    for(i=2;i<=MAXN+3;i++)
    {
        if(prime[i]==1)
        {
            for(j=i*i;j<=MAXN+3;j+=i)
                prime[j]=0;
        }
    }
    for(i=1;i<=MAXN+2;i++)
    {
       count_prime[i] = count_prime[i-1];
       if(prime[i]==1)
            count_prime[i]++;
    }
}

ll binary_exponentation(ll a, ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
            res=(res*a)%big;
        a=(a*a)%big;
        b>>=1;
    }
    return res;
}



int main()
{
    phi_1_to_n();
    sieve_of_erastothenes();
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, fn;
        cin >> n;
//        cout << "count_prime: " << count_prime << endl;
//        cout << "phi[n]: " << phi[n] << endl;
        fn = count_prime[n] - phi[n];
//        cout << "fn: " << fn << endl;
        if(fn < 0)
            fn = 0;
        ll factorial=1;

        for(i=1;i<=fn;i++)
        {
            factorial*=i;
        }
//                cout << "factorial: "<<factorial << endl;

        cout << binary_exponentation(phi[n] , factorial) << endl;

    }
}