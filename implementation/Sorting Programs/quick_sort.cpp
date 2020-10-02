#include <iostream>
using namespace std;
void swap1(int &a,int &b)
{
    int t;
    t=a;
    a=b;
    b=t;
}
int partition1(int A[],int l,int h)
{
    int pivot=A[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++)
    {
        if(A[j]<=pivot)
        {
            i++;
            swap1(A[i],A[j]);
        }
    }
    swap1(A[i+1],A[h]);
    return (i+1);
}
void quicksort(int A[],int l,int h)
{
    if(l<h)
    {
        int p=partition1(A,l,h);
        quicksort(A,l,p-1);
        quicksort(A,p+1,h);
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
    quicksort(A,0,N-1);
    cout<<"Sorted array: "<<endl;
    for(i=0;i<N;i++)
        cout<<A[i]<<" ";
    return 0;
}
