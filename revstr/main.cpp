#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
int rev(char p[],int n,int m)
{
    for(int i=n,j=m;i<j;i++,j--)
    {
        p[i]^=p[j];
        p[j]^=p[i];
        p[i]^=p[j];
    }
}
void revwords(char p[])
{
    strrev(p);int i,j;
    for(i=0;p[i];i++)
    {
        j=i;
        while(p[i]&&!isspace(p[i]))
            i++;
        rev(p,j,i-1);
    }
    p[i]='\0';
}
int main()
{
    char p[]="yeshwanth be b.tech";
    revwords(p);
    for(int i=0;p[i]
    ;i++)
    cout<<p[i];
    return 0;
}
