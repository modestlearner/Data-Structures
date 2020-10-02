#include <iostream>
using namespace std;
void Insertionsort(int A[],int N)
{
    int i,j,t;
    for(i=1;i<=N-1;i++)
    {
        t=A[i];
        j=i-1;
        while(t<A[j]&&j>=0)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=t;
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
        Insertionsort(A,N);
        cout<<"Sorted array: "<<endl;
        for(i=0;i<N;i++)
            cout<<A[i]<<" ";
    return 0;
}
