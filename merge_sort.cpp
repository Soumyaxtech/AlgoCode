#include<iostream>

using namespace std;

void merge(int arr[],int l,int mid,int r){
    int n1=(mid-l+1);
    int n2=(r-mid);
    int arr1[n1],arr2[n2];
    for(int i=0;i<n1;i++){
        arr1[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            k++;
            i++;
        }
        else{
            arr[k]=arr2[j];
            k++;
            j++;  
        }
    }
    while(i<n1){
        arr[k]=arr1[i];
        i++;
        k++;
    }
     while(j<n2){
        arr[k]=arr2[j];
        j++;
        k++;
    }

}

void merge_sort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

void display(int arr[],int n){
   for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
   } 
}

int main(){
    int n;
    cout<<"Enter the num of element ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<i+1<<" element "<<" ";
        cin>>arr[i];
    }
    cout<<"UNSORTED ARRAY "<<endl;
    display(arr,n);
    cout<<endl;
    cout<<"SORTED ARRAY "<<endl;
    merge_sort(arr,0,n-1);
    display(arr,n);
    return 0;
}