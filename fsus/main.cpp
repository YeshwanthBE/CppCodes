#include <iostream>
#include <stack>
using namespace std;
void fs(int ar[],int br[],int sr[])
{
    stack<int> s;
    for(int i=0;i<6;i++)
    {
        if(!s.empty()&&br[i]>=br[s.top()])
            s.pop();
        if(s.empty())
            sr[i]=i+1;
        else
            sr[i]=i-s.top();
        s.push(i);
    }
}
int main()
{
    int ar[6]={0,1,2,3,4,5};
    int br[6]={6,3,4,5,5,6};int sr[6];
    fs(ar,br,sr);
    for(int i=0;i<6;i++)
        cout<<ar[i]<<' '<<br[i]<<' '<<sr[i]<<endl;
    return 0;
}
