#include <iostream>
using namespace std;
void Bubblesort(int A[],int N)
{
    int i,j,t;
    for(i=0;i<=N-2;i++)
        for(j=0;j<=N-2-i;j++)
        if(A[j]>A[j+1])
        {
            t=A[j];
            A[j]=A[j+1];
            A[j+1]=t;
        }
}
int main()
{
    int A[200],N,i;
    cout<<"Enter no. of elements to be taken: ";
    cin>>N;
    cout<<"Enter the elements of array: "<<endl;
    for(i=0;i<N;i++)
        cin>>A[i];
    Bubblesort(A,N);
    cout<<"Sorted array: "<<endl;
    for(i=0;i<N;i++)
    	cout<<A[i]<<" ";
    return 0;
}
