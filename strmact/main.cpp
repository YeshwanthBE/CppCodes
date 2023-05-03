#include <iostream>

using namespace std;
int strmat(char *a,int n,char *p,int m)
{
    for(int i=0;i<n-m;i++)
    {
        int j=0;
        while(a[i+j]==p[j])
            j++;
        if(j==m)
            return 1;
    }
    return 0;
}
int main()
{
    char a[13]="Hello world!";
    char p[7]=" world";
    cout<<strmat(a,12,p,5);
    return 0;
}
