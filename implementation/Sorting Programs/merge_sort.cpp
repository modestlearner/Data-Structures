#include <iostream>
using namespace std;
void merging(int A[],int l,int m,int r)
{
    int i,j,k,n1,n2;
    n1=m-l+1;
    n2=r-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i]=A[l+i];
    for(j=0;j<n2;j++)
        R[j]=A[m+1+j];
    i=0;
    j=0;
    k=l;
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        A[k]=R[j];
        j++;
        k++;
    }
}
void mergesort(int A[],int l,int r)
{
    if(l<r)
    {
        //Same as (l+r)/2, but avoids overflow for large l and h
        int m=l+(r-l)/2;
        mergesort(A,l,m);
        mergesort(A,m+1,r);
        merging(A,l,m,r);
    }
}
int main()
{
    int A[200],N,i;
    cout<<"Enter total no. of elements to be sorted: ";
    cin>>N;
    cout<<"Enter the elements of array: "<<endl;
    for(i=0;i<N;i++)
        cin>>A[i];
    mergesort(A,0,N-1);
    cout<<"Sorted array: "<<endl;
    for(i=0;i<N;i++)
        cout<<A[i]<<" ";
    return 0;
}
