#include <iostream>
#include<cstring>
using namespace std;
void permuntation(int depth,char *str,int *used,char *ori)
{
    int len=strlen(ori);
    if(depth==len)
        cout<<str[0]<<str[1]<<str[2]<<endl;
    else
    {
        for(int i=0;i<len;i++)
            if(!used[i])
                {
                    used[i]=1;
                    str[depth]=ori[i];
                    permuntation(depth+1,str,used,ori);
                    used[i]=0;
                }
    }
}
void combination(int depth,char *str,int strt,char *ori)
{
    int len=strlen(ori);
        for(int i=strt;ori[i];i++)
        {
            str[depth]=ori[i];
            str[depth+1]='\0';
            cout<<str<<endl;
            if(depth<len-1);
                combination(depth+1,str,i+1,ori);
        }
}
int main()
{
    char ori[4]="abc";
    int used[3]={0};char str[4]="";
    combination(0,str,0,ori);
    return 0;
}
