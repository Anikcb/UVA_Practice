#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair <ll, ll> pll;
#define mxx 605
char T[mxx];
ll RA[mxx], tempRA[mxx];
ll SA[mxx], tempSA[mxx];
ll c[mxx],n;
ll Phi[mxx];
ll PLCP[mxx];
ll LCP[mxx];

void countingSort(ll k)
{
    ll i, sum, maxi = max(300ll, n);
    memset(c, 0, sizeof c);
    for (i = 0; i < n; i++)
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++)
    {
        ll t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (i = 0; i < n; i++)
        tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)
        SA[i] = tempSA[i];
}

void constructSA()
{
    ll i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];
    for (i = 0; i < n; i++) SA[i] = i;
    for (k = 1; k < n; k <<= 1)
    {
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        for (i = 1; i < n; i++)
            tempRA[SA[i]] =
                (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < n; i++)
            RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break;
    }
}


void computeLCP()
{
    ll i, L;
    Phi[SA[0]] = -1;
    for (i = 1; i < n; i++)
        Phi[SA[i]] = SA[i-1];
    for (i = L = 0; i < n; i++)
    {
        if (Phi[i] == -1)
        {
            PLCP[i] = 0;
            continue;
        }
        while (T[i + L] == T[Phi[i] + L]) L++;
        PLCP[i] = L;
        L = max(L-1, 0ll);
    }
    for (i = 0; i < n; i++)
        LCP[i] = PLCP[SA[i]];
}


int main()
{
//    freopen("input.txt","rt", stdin);
//    freopen("output.txt","wt", stdout);
    ll cnt=1;
    char ch1[305],ch2[305];
    while(cin>>ch1>>ch2)
    {
        vector<string>v;
        ll res=0;
        strcat(T,ch1);
        strcat(T,"#");
        strcat(T,ch2);
        n = (int)strlen(T);
        ll x=strlen(ch1);
        ll y=strlen(ch2);
        T[n++] = '$';
//        cout<<"T = "<<T<<endl;
        constructSA();
        computeLCP();
//        for (ll i = 0; i < n; i++)
//        printf("%2lld%2lld\t%s\n", SA[i], LCP[i], T + SA[i]);

        for(ll i=1;i<n;i++)
        {
            ll a=min(SA[i],SA[i-1]);
            ll b=max(SA[i],SA[i-1]);
//            cout<<a<<" - "<<b<<endl;
            if(a<x && b>x)res=max(res,LCP[i]);
        }
//        cout<<"res = "<<res<<endl;
        for(ll i=1;i<n;i++)
        {
            ll a=min(SA[i],SA[i-1]);
            ll b=max(SA[i],SA[i-1]);
            if(LCP[i]==res && a<x && b>x)
            {
                string s;
                for(ll j=SA[i];j<SA[i]+LCP[i];j++)s+=T[j];
                if(s.size()>0)v.push_back(s);
            }
        }
        if(cnt>1)cout<<endl;
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());
        for(ll i=0;i<v.size();i++)cout<<v[i]<<endl;
        if(v.size()==0)cout<<"No common sequence."<<endl;
        memset(T,0,sizeof(T));
        cnt++;
    }
}
