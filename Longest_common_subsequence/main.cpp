#include <iostream>
using namespace std;
int ar[4][2];
int Memoi_LCS(char *p,char *q,int i=0,int j=0)
{
    if(p[i]=='\0'||q[j]=='\0')
        return 0;
    else if (ar[i][j])
        return ar[i][j];
    else if(p[i]==q[j])
        ar[i][j]=Memoi_LCS(p,q,i+1,j+1)+1;
    else
        ar[i][j]=max(Memoi_LCS(p,q,i,j+1),Memoi_LCS(p,q,i+1,j));

    return ar[i][j];
}


int Rec_LCS(char *p,char *q,int i=0,int j=0)
{
    if(p[i]=='\0'||q[j]=='\0')
        return 0;
    else if(p[i]==q[j])
        return Rec_LCS(p,q,i+1,j+1)+1;
    else
        return max(Rec_LCS(p,q,i,j+1),Rec_LCS(p,q,i+1,j));
}
int main()
{
    char *p="abcd",*q="bd";
    cout<<Memoi_LCS(p,q);
    return 0;
}
