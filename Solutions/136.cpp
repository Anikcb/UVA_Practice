#include<stdio.h>
int main()
{
   int i,n,check,b,s=1;
   scanf("%d",&n);
   for(i=2;   ;i++){
        //printf("i=%d\n",i);

        check=0;
    if(i%2==0||i%3==0||i%5==0){
            b=i;
  // printf("b1111=%d\n",b);

        while(b!=0){
            if(b%2==0){
                b=b/2;
                //printf("b2222=%d\n",b);
            }
            else if(b%3==0){
                b=b/3;
                //printf("b3333=%d\n",b);
            }
            else if(b%5==0){
                b=b/5;
               // printf("b4444=%d\n",b);
            }
            else{
                    if(b==1){
                        //printf("b5555=%d\n",b);
                        break;
                    }
                    else{
                //printf("b6=%d\n",b);
                check=1;
                 break;
                    }
            }
        }
        if(check==0){
            s=s+1;
           // printf("s=%d\n",s);
        }
        if(n==s){
            printf("Ans=%d\n",i);
            break;
        }
    }
   }

return 0;
}
