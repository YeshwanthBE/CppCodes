#include <iostream>

using namespace std;
void radrc(char *str)
{
    int i,j;
    for(i=0,j=1 ;str[j];j++)
    {
        while(str[i]==str[j]&&i>=0)
        {
            j++;i--;
        }
            str[++i]=str[j];
    }

    str[++i]='\0';
    cout<<str;
}
int main()
{
    char p[10]="ABCCBCBA";
    radrc(p);
    return 0;
}
