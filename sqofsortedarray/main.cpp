#include <iostream>

using namespace std;

void disp(int ar[],int n)
{
    for(int i=0;i<n;i++)
        cout<<ar[i]<<' ';
}
int* sqofsrtdar(int ar[],int n)
{
   int *sqar=new int[n];
   int i=0,j,k=0;
   while(i<n&&ar[i]<0)
    i++;
   j=i--;
   while(i>=0&&j<n)
   {
       if(-ar[i]<ar[j])
       {sqar[k]=ar[i]*ar[i];i--;}
       else
       {sqar[k]=ar[j]*ar[j];j++;}
       k++;
   }
   while(i>=0)
   {sqar[k++]=ar[i]*ar[i];i--;}
   while(j<n)
    {sqar[k++]=ar[j]*ar[j];j++;}
    disp(sqar,n);
}
int main()
{
    int ar[6]={-6,-5,-4,1,2,3};
    sqofsrtdar(ar,6);
    return 0;
}
