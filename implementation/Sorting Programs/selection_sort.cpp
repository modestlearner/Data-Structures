#include <iostream>
using namespace std;
void Selectionsort(int A[],int n)
{
    int i,j,small,pos,temp;
    for(i=0;i<=n-2;i++)
    {
        small=A[i];
        pos=i;
        for(j=i+1;j<=n-1;j++)
        if(A[j]<small)
        {
            small=A[j];
            pos=j;
        }
        temp=A[i];
        A[i]=A[pos];
        A[pos]=temp;
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
    Selectionsort(A,N);
    cout<<"Sorted array: "<<endl;
    for(i=0;i<N;i++)
        cout<<A[i]<<" ";
    return 0;
}
