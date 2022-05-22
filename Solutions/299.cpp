#include<bits/stdc++.h>
#define sc scanf
#define pf printf
#define ll long long
#define pi 2*acos(0.0)

#define ff first
#define se second
#define inf (1<<30)                                              //infinity value
#define pb push_back
#define mod  1000000007
#define ST(v) sort(v.begin(),v.end())
#define cover(a,d) memset(a,d,sizeof(a))
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define maxall(v) *max_element(v.begin(),v.end())
#define minall(v) *min_element(v.begin(),v.end())
#define un(v) ST(v), v.erase(unique(v.begin(),v.end()),v.end())
using namespace std;
int arr[10000];
int loc(int i,int a)
{
    int j;
    for(j=1;j<=a;j++){
        if(arr[j]==i){
            return (j);
            break;
        }
    }

}
int main()
{
    int n,i,a,swap,j,x,k,lb;
  
    arr[0]=10;
    scanf("%d",&n);
    for(j=1; j<=n; j++)
    {
        x=0;
        scanf("%d",&a);
        for(i=1; i<=a; i++)
        {
            scanf("%d",&arr[i]);
        }
        for(i=1; i<=a; i++)
        {
            lb=loc(i,a);
           // printf("lb = %d\n",lb);
            for(k=lb; k>i; k--)
            {
               // printf("%d %d\n",arr[k],arr[k-1]);
                swap=arr[k];
                arr[k]=arr[k-1];
                arr[k-1]=swap;
                x++;
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",x);
    }



    return 0;
}
