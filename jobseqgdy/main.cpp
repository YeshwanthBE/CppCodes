#include <iostream>

using namespace std;
struct job
{
    int job_no=-1;
    float deadline=0;
    float profit=0;
    job *nxt=NULL;
};
job* ctjob(float p,float w,int ino)
{
        job *i=new job;
        i->deadline=w;
        i->profit=p;
        i->job_no=ino;
        return i;
}
job* japnd(job *head,float p,float w)
{
    if(!head)
        head=ctjob(p,w,1);
    else
    {
        while(head->nxt)
            head=head->nxt;
    head->nxt=ctjob(p,w,head->job_no+1);
    }
    return head;
}
void dispjob(job *a)
{
    cout<<a->job_no<<'\t'<<a->profit<<'\t'<<a->deadline<<'\t'<<endl;
}
void swp(job **a,job **b)
{
    job *temp=*a;
    *a=*b;
    *b=temp;
}
struct heap
{
    job* data[12];
    int cnt=0;
    int capacity=12;
}*head=NULL;
void plup(heap *h)
{
    int i=h->cnt-1;
    while(i>0&&(h->data[i]->profit>h->data[(i-1)/2]->profit))
    {
        swp(&h->data[i],&h->data[(i-1)/2]);
        i=(i-1)/2;
    }
}
void pldw(heap *h)
{
    int i=0,j=i*2+1;
    while(j<h->cnt&&(h->data[i]->profit<h->data[j]->profit||h->data[j]->profit<h->data[j+1]->profit))
    {
        j=h->data[j]->profit>h->data[j+1]->profit?j:j+1;
        swp(&h->data[i],&h->data[j]);
        i=j;
        j=i*2+1;
    }
}
heap* cthp(job *k,heap *h)
{
    if(!h)
        h=new heap;
    if(h->cnt+1>h->capacity)
        return h;
    h->data[h->cnt++]=k;
    plup(h);
    return h;
}
job* del(heap *h)
{
    job* temp=h->data[0];
    h->data[0]=h->data[h->cnt-1];
    h->cnt--;
    pldw(h);
    return temp;
}
job * jobcrete()
{
    job*j=japnd(NULL,35,3);
    japnd(j,30,4);japnd(j,25,4);japnd(j,20,2);
    japnd(j,5,2);japnd(j,12,1);japnd(j,15,3);
    return j;
}
heap *heapcrete(job *jh)
{
    heap *hh=NULL;
    while(jh)
    {
        hh=cthp(jh,hh);
        jh=jh->nxt;
    }
    return hh;
}
void hdisp(heap *hh)
{
   cout<<"jobno profit  deadline\n";
    while(hh->cnt)
    {
        job *t=del(hh);
        cout<<t->job_no<<'\t'<<t->profit<<'\t'<<t->deadline<<endl;
    }

}
void js(heap *h)
{
    job *sj[4]={NULL};
    int cnt=4;int i;
    while(cnt&&h->cnt)
    {
        job *t=del(h);
        for(i=t->deadline-1;i>=0;i--)
            if(!sj[i])
                break;
        if(i>=0)
            {sj[i]=t;cnt--;}
        else
            continue;

    }
    int mxp=0;
    cout<<"Job_No Profit Deadline\n";
    for(int i=0;i<4;i++)
        {dispjob(sj[i]);mxp+=sj[i]->profit;}
    cout<<"Maximum Profit="<<mxp;
}
int main()
{
    job *j=jobcrete();
    heap *h=heapcrete(j);
    //hdisp(h);
    js(h);
    return 0;
}
