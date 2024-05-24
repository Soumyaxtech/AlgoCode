#include<iostream>


using namespace std;
void MAX_MIN(int arr[],int low,int high,int *max,int *min){

        if(low==high){
            *max=*min=arr[low];
            return;
        }
        else if(high==low+1){

            if(arr[low]>arr[high]){
                *max=arr[low];
                *min=arr[high];
            }
            else{
                 *min=arr[low];
                *max=arr[high];
            }
        }
        else{
            int mid=(low+high)/2;
            int left_max,left_min,right_max,right_min;
            MAX_MIN(arr,low,mid,&left_max,&left_min);
            MAX_MIN(arr,mid+1,high,&right_max,&right_min);
            if(left_max>right_max){
                *max=left_max;
            }
            else{
                *max=right_max;
            }
            if(left_min<right_min){
                *min=left_min;
            }
            else{
                *min=right_min;
            }
        }
        return;
}

int main(){
    int n;
    cout<<"Enter number of element in array ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<i+1<<" element"<<" ";
        cin>>arr[i];

    }
    int max,min;
    MAX_MIN(arr,0,n-1,&max,&min);
    cout<<"Max Element"<<max<<endl;
    cout<<"Min Element"<<min;
    return 0;
}