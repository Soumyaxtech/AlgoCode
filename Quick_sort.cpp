#include<iostream>

using namespace std;

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}

int pertition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void Quick_sort(int arr[],int low,int high){
    if(low<high){
        int k=pertition(arr,low,high);
        for(int i=low;i<k;i++){
            cout<<arr[i];
        }
        cout<<"pivot is "<<arr[k];
        Quick_sort(arr,low,k-1);
        Quick_sort(arr,k+1,high);
    }
}


int main(){
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
    cout<<"SORTED ARRAY --->"<<" ";
    Quick_sort(arr,0,n-1);
    display(arr,n);
}