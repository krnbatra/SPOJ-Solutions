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
#define NO_OF_CHARS 256

const ll MAXN = (ll)1e7;

ll i, j, k;

vll LCM(MAXN+1);
vector<ll> phi(MAXN+1);

vll permuted;

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

    for(i=21 ; i< MAXN+1 ; i++)
    {
        string s1, s2;
        int check = 1;
        s1 = to_string(i);
        s2 = to_string(phi[i]);
        int count[NO_OF_CHARS] = {0};
        for (j = 0; s1[j] && s2[j];  j++)
        {
            count[s1[j]]++;
            count[s2[j]]--;
        }
        if (s1[j] || s2[j])
          check = 0;

        for (i = 0; i < NO_OF_CHARS; i++)
            if (count[i])
                check =0;
         if(check == 1)
            permuted.push_back(i);
    }

}



int main()
{
    phi_1_to_n();
    int t;
    cin >> t;
    while(t--)
    {
        int n, ans, c=0 ;
        double x=INT_MAX;
        cin >> n;
        for(i=0; i<permuted.size(); i++)
        {
            if(permuted[i]<=n)
            {
                double division = ((double)permuted[i]/(double)phi[permuted[i]]);
                if(x >= division)
                {
                    ans = permuted[i];
                    x=division;
                    c=1;
                }

            }
            else
                break;
        }
        if(c==1)
        cout << ans << endl;
        else
            cout << "No solution" << endl;

    }

}

