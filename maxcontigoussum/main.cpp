#include <iostream>

using namespace std;
int mcs(int ar[],int s,int e)
{
    int mxls=0,mxrs=0;
    if(s==e)
        return ar[s]>0?ar[s]:0;
    int mid=s+(e-s)/2;
    mxls=mcs(ar,s,mid);
    mxrs=mcs(ar,mid+1,e);
    int ls=0,rs=0,mls=0,mrs=0;
    for(int i=mid;i>=s;i--)
        {
            ls+=ar[i];
            mls=mls>ls?mls:ls;
        }
    for(int j=mid+1;j<=e;j++)
        {
            rs+=ar[j];
            mrs=mrs>rs?mrs:rs;
        }
    if(mxls>mxrs)
        return mxls>(mrs+mls)?mxls:(mrs+mls);
    else
        return mxrs>(mrs+mls)?mxrs:(mrs+mls);

}
int main()
{
    int ar[6]={-2,11,-4,13,-5,2};
    cout<<mcs(ar,0,5);
    return 0;
}
