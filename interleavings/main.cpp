#include <iostream>

using namespace std;
void il(char *p,int plen,char *q,int qlen,char *pq,int m=0,int n=0,int i=0)
{
    if(m>plen-1&&n>qlen-1)
    {
        pq[i]='\0';
        cout<<pq<<endl;
        return;
    }
    if(m<plen)
    {
        pq[i]=p[m];
        il(p,plen,q,qlen,pq,m+1,n,i+1);
    }
    if(n<qlen)
    {
        pq[i]=q[n];
        il(p,plen,q,qlen,pq,m,n+1,i+1);
    }
}
int main()
{
    char p[]="AB";char q[]="CD";char pq[5];
    il(p,2,q,2,pq);
    return 0;
}
