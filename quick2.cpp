#include <iostream>
using namespace std;

int partition(int arr[], int l, int r)
{
    int pivot = arr[l];
    int i = l-1;
    int j = r + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
        {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

void quick_Sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);

        quick_Sort(arr, l, p);
        quick_Sort(arr, p+1, r);
        return;
    }
}


void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}

int main()
{
    int n;
    cout<<"Enter num of element in array ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<i+1<<" element"<<" ";
        cin>>arr[i];
    }
    cout<<"UNSORTED ARRAY --->"<<" ";
    display(arr,n);
    cout<<endl;
    cout<<"SORTED ARRAY --->"<<" ";
    quick_Sort(arr,0,n-1);
    display(arr,n);
}