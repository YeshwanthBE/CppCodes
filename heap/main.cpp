#include <iostream>
#include <queue>
using namespace std;
struct heap
{
    int data[12];
    int cnt=0;
    bool type=false;
}root;
void plup()
{
    int i=root.cnt-1,j=(i-1)/2;
    while(i>=0&&root.data[i]>root.data[j])
    {
     int temp=root.data[j];
     root.data[j]=root.data[i];
     root.data[i]=temp;
    i=j;
    j=(i-1)/2;
    }
}
void pldn()
{
    int i=0,j=i*2+1;
    while((j<root.cnt)&&(root.data[i]<root.data[j]||root.data[i]<root.data[j+1]))
    {
        j=root.data[j]>root.data[j+1]?j:j+1;
        int temp =root.data[i];
        root.data[i]=root.data[j];
        root.data[j]=temp;
        i=j;
        j=i*2+1;
    }
}
void del()
{
    cout<<root.data[0]<<endl;
    root.data[0]=root.data[root.cnt-1];
    root.cnt--;
    pldn();
}
void ct(int data)
{
    if(root.cnt==0)
        root.data[root.cnt++]=data;
    else
    {
        if(root.cnt<12)
        root.data[root.cnt++]=data;
        else
        return;
    }
    plup();
}
void disp()
{
    for(int i=0;i<root.cnt;i++)
        cout<<root.data[i]<<' ';
    cout<<endl;
}
void mn()
{
    int cnt=root.cnt-2;int mn=INT_MAX;
    for(int i=cnt+1;i>=cnt/2;i--)
        mn=mn>root.data[i]?root.data[i]:mn;
    cout<<mn<<endl;
}
void ltk(int k)
{
    for(int i=0;i<root.cnt;i++)
        if(root.data[i]<k)
        cout<<root.data[i]<<' ';
}
int main()
{
    int ar[12]={31,10,16,9,8,14,12,3,100,5,7,19};
    for(int i=0;i<12;ct(ar[i++]));
    disp();
    ltk(20);
    return 0;
}
