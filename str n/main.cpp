#include <iostream>
#include<cstring>
using namespace std;

int main()
{
    int n;
    cout<<"enter total no ";
    cin>>n;
    string ptr[n];
    cout<<"enter the string\n";
    for (int i=0;i<n;i++)
    {cin>>ptr[i];}
    for(int i=0;i<n;i++)
        {
            int k=0;
            for(int j=i+1;j<n;j++)
            if(ptr[i]==ptr[j])
                {
                    k++;
                    ptr[j]=ptr[j]+"("+to_string(k)+")";
                }
        }
        cout<<endl<<endl<<endl;
    for(int i=0;i<n;i++)
        cout<<ptr[i]<<endl;
    return 0;
}
