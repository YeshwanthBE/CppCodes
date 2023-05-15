#include <iostream>
using namespace std;
int dr[6][4];
int Dp_LCS(char *p,char *q,int i=5,int j=3)
{
    if(!i||!j)
        return 0;
    if(dr[i][j])
        return dr[i][j];
    if(p[i-1]==q[j-1])
        dr[i][j]=Dp_LCS(p,q,i-1,j-1)+1;
    else
        dr[i][j]=max(Dp_LCS(p,q,i,j-1),Dp_LCS(p,q,i-1,j));
    return dr[i][j];

}
int mr[4][2];
int Memoi_LCS(char *p,char *q,int i=0,int j=0)
{
    if(p[i]=='\0'||q[j]=='\0')
        return 0;
    else if (mr[i][j])
        return mr[i][j];
    else if(p[i]==q[j])
        mr[i][j]=Memoi_LCS(p,q,i+1,j+1)+1;
    else
        mr[i][j]=max(Memoi_LCS(p,q,i,j+1),Memoi_LCS(p,q,i+1,j));
    return mr[i][j];
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
    char *p="abcde",*q="bde";
    cout<<Dp_LCS(p,q);
    return 0;
}
