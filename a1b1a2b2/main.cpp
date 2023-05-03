#include <iostream>
#include <cstring>
using namespace std;
void swp(char *a,char *b)
{
    char t=*a;
    *a=*b;
    *b=t;
}
void ia(char *str,int s,int e,int len)
{
    int mid=s+(e-s)/2;
    int im=s+(mid-s)/2+1;
    for(int i=im,j=mid+1;i<=mid;i++,j++)
        swp(&str[i],&str[j]);
    if(s==e)
        return;
    ia(str,s,mid,len/2);
    ia(str,mid+1,e,len/2);
}
int main()
{
    char ab[9]="13572468";
    ia(ab,0,7,8);
    cout<<ab;
    return 0;
}
