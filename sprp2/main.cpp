#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
void sprp(char *p)
{
    int noofsp=0;
    for(int i=0;p[i];i++)
        if(isspace(p[i]))
            noofsp++;
    noofsp*=2;
    noofsp+=strlen(p);
    p[noofsp--]='\0';
    int i=strlen(p)-1;
    while(i>=0)
    {
        if(isspace(p[i]))
            {
                p[noofsp--]='0';
                p[noofsp--]='2';
                p[noofsp--]='%';
            }
        else
            p[noofsp--]=p[i];
        i--;
    }
    cout<<p;
}
int main()
{
    char p[9]="A  B";
    sprp(p);
    return 0;
}
