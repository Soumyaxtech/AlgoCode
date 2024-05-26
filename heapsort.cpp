#include<iostream>

using namespace std;

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[],int n){
    for(int i=(n/2-1);i>=0;i--){
        heapify(arr,n,i);
        cout<<"build heap step "<<endl;
        for(int j=0;j<n;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;

    }
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        cout<<"extract max step "<<endl;
        for(int j=0;j<n;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
        heapify(arr,i,0);
        cout<<"heapify step "<<endl;
        for(int j=0;j<n;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
}

void display(int arr[],int n){
    for(int j=0;j<n;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
}

int main(){
    int n;
    cout<<"enter number of element ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
           cout<<i+1<<" element ";
           cin>>arr[i];
        }
    cout<<"UNSORTED ARRAY ";
    display(arr,n);
    heapsort(arr,n);
    cout<<"SORTED ARRAY ";
    display(arr,n);
    return 0;
}