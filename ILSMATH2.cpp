#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
const double lp=2.302585092994;
const double pi=4.0*atan(1.0);
double n,d;
int l,r,m;
double loga(int m){
    double k=double(m)+1;
    double res=(k-0.5)*log(k)-k+0.5*log(2.0*pi)+1.0/(12.0*k);
    return res/lp;
}
int main(){
    scanf("%lf\n",&n);
    if (n>=500.0){
        l=1,r=int(1e9);
        while (l<r){
            m=(l+r+1)>>1;
            if (loga(m)>n) r=m-1;
            else l=m;
        }
        d=loga(l);
        if (d<=n && n<=d+1.0){
            printf("1\n");
            printf("%d\n",l);
        }else printf("NO\n");
        return 0;
    }
    if (n==1){
         printf("%d\n%d %d %d",3,1,2,3);
         return 0;
    }
    if (n==2){
        if (n==2) printf("%d\n%d",1,4);
        return 0;
    }
    if (n==3){
        if (n==3) printf("%d\n%d %d",2,5,6);
        return 0;
    }
    double d=1.0;
    double s=0.0;
    while (s<=n){
        d=d+1.0;s=s+log10(d);
        if (int(s)+1==n){
            printf("1\n%.lf\n",d);
            return 0;
        }
    }
    puts("NO");
    return 0;
}

