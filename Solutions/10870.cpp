//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>

//using    namespace __gnu_pbds;
using namespace std;


/*** Typedef ***/
typedef long long ll;
typedef unsigned long long ull;


/*** STLs ***/
typedef vector <ll> vll;
typedef set <ll> sll;
typedef multiset <ll> msll;
typedef queue <ll> qll;
typedef stack <ll> stll;
typedef map <ll, ll> mll;
typedef pair <ll, ll> pll;
typedef vector <pair <ll, ll> > vpll;
typedef map<string,ll> msl;
typedef priority_queue<ll> pql;
typedef priority_queue<ll,vector<ll>,greater<ll> > npql;


/*** Values ***/
const int N = 100005;
const int inf = 1234567890;
const ll INF = 1122334455667788990;


/*** Define Values ***/
#define     S                 second
#define     re                return
#define     MP                make_pair
#define     pb                push_back
#define     SZ(x)             ((ll) (x).size())
#define     EPS               10E-10
#define     iseq(a,b)         (fabs(a-b)<EPS)
#define     PI                3.141592653589793238462643
#define     HAR               0.57721566490153286060651209
#define     Ceil(a,b)         (a+b-1)/b
#define     gcd(a, b)         __gcd(a,b)
#define     lcm(a, b)         ((a)/gcd(a,b))*(b)
#define     input             freopen("input.txt","rt", stdin)
#define     output            freopen("output.txt","wt", stdout)
#define     all(v)            v.begin(),v.end()
#define     en                cout << '\n';
#define     no                cout << "NO" << '\n'
#define     yes               cout << "YES" << '\n'
#define     memz(u)           memset(u, 0, sizeof u)
#define     memn(u)           memset(u, -1, sizeof u)
#define     ps(x,y)           fixed<<setprecision(y)<<x
#define     foR0(num)         for(ll i = 0; i < num; i++)
#define     foR1(num)         for(ll i = 1; i <= num; i++)
#define     rep(i, x, n)      for (ll i = x, _n = (n); i < _n; ++i)
#define     forIn(arr, num)   for(ll i = 0; i < num; i++) cin>>arr[i];
#define     forIn1(arr, num)  for(ll i = 1; i <= num; i++) cin>>arr[i];
#define     Unique(X)         (X).resize(unique(all(X))-(X).begin())
#define     IOS               ios_base::sync_with_stdio(false); cin.tie(NULL);


ll MOD;

void mulMat(ll F[15][15], ll M[15][15],ll d)
{
    ll rslt[15][15];
    for (ll i = 0; i < d; i++)
    {
        for (ll j = 0; j < d; j++)
        {
            rslt[i][j] = 0;
            for (ll k = 0; k < d; k++)
            {
                rslt[i][j] = (rslt[i][j]+(F[i][k] * M[k][j])%MOD)%MOD;
            }
        }
    }

    for(ll i=0; i<d; i++)
    {
        for(ll j=0; j<d; j++)
        {
            F[i][j]=rslt[i][j];
        }
    }
}


void power(ll F[15][15], ll n, ll a[], ll d)
{
    if (n == 0 || n == 1)return;
    ll M[15][15]={};
    foR0(d)M[0][i]=a[i];
    for(ll i=1,j=0;i<d;i++,j++)M[i][j]=1;

    power(F, n / 2, a, d);
    mulMat(F, F, d);
    if (n&1)mulMat(F, M, d);
}

ll matrix_expo(ll n, ll a[], ll arr[],ll d)
{
    ll F[15][15]={};
    foR0(d)F[0][i]=a[i];
    for(ll i=1,j=0;i<d;i++,j++)F[i][j]=1;

    if (n == 0)return 0;
    power(F, n, a, d);

    ll res=0;
    for(ll i=0; i<d; i++)
    {
        res=(res+(F[0][i]*arr[i])%MOD)%MOD;
    }
    return res;
}


int main()
{
    IOS;
    ll tst=1;
//    cin>>tst;
    for(ll tt=1; ; tt++)
    {
        //code
        ll arr[17],a[17];
        ll n,d,m;
        cin>>d>>n>>m;
        if(d==0 && n==0)break;
        forIn(a,d);
        forIn(arr,d);
        MOD=m;

        if(n<=d)cout<<arr[n-1]<<endl;
        else
        {
            reverse(arr,arr+d);
            ll val = matrix_expo(n-d, a, arr, d);
            cout<<val<<endl;
        }



    }


    return 0;
}
