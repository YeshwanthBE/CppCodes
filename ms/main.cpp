#include <iostream>

using namespace std;
void swp(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void disp(int ar[],int n)
{
    for(int i=0;i<n;i++)
        cout<<ar[i]<<' ';
    cout<<endl;
}
int partion(int ar[],int L,int R)
{
    if(L>R)
        return 0;
    int lb=L,ub=R;
    int pivot=lb;
    while(lb<ub)
    {
        while(ar[lb]<=ar[pivot])
            lb++;
        while(ar[ub]>ar[pivot])
            ub--;
        if(lb<ub)
        swp(&ar[lb],&ar[ub]);
    }
    swp(&ar[pivot],&ar[ub]);
    partion(ar,L,ub-1);
    partion(ar,ub+1,R);
    return ub;
}

void ms(int ar[],int l,int r,int k)
{
    if(l==r)
        return ;
    int pos=partion(ar,l,r);
    if(pos==k)
        cout<<ar[pos];
    else if(pos<k)
        ms(ar,pos+1,r,k);
    else
        ms(ar,l,pos-1,k);
    return;
}
int main()
{
    int ar[13]={2,3,1,65,1,65,165,3,65,32,489,4,32};
    ms(ar,0,12,5);
    //disp(ar,12);
    return 0;
}
