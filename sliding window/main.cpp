#include <iostream>
#include <cstring>
using namespace std;
void sw(char *s,char *t)
{
    int tlen=strlen(t),slen=strlen(s);
    int hasfound[256]={0},shouldfind[256]={0};
    for(int i=0;i<tlen;i++)
        shouldfind[t[i]]++;
    int windowlen=tlen,strt,ed,cnt=0;
    while(windowlen<=slen)
    {
        strt=0;ed=windowlen-1;
        while(ed<slen)
        {
            int hasfound[256]={0};
            for(int i=strt;i<=ed;i++)
                if(shouldfind[s[i]])
                    {
                        if(hasfound[s[i]]<shouldfind[s[i]])
                            cnt++;
                        hasfound[s[i]]++;
                    }
            if(cnt==tlen)
                {cout<<strt<<' '<<ed<<endl;return;}
            cnt=0;
            strt++;
            ed++;
        }
        windowlen++;
    }
}
int main()
{
    char p[9]="ABCDFF";char t[10]="AFF";
    sw(p,t);
    return 0;
}
