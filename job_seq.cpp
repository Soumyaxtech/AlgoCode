#include<iostream>

using namespace std;

void sort(int p[],int d[],int n){
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(p[j]<p[j+1]){
                swap(p[j],p[j+1]);
                swap(d[j],d[j+1]);
            }
        }
    }
}

int max(int arr[],int n){
    int m=arr[1];
    for(int i=2;i<=n;i++){
        if(arr[i]>m){
            m=arr[i];
        }
    }
    return m;
}

void display(int p[],int d[],int n){
    for(int i=1;i<=n;i++){
        cout<<"PROFIT "<<p[i]<<" DEADLINE "<<d[i]<<endl;
    }
}

int job_seq(int p[],int d[],int n){
    sort(p,d,n);
    int max_d=max(d,n);
    int g[max_d+1]={0};
    for(int i=1;i<=n;i++){
        for(int j=d[i];j>0;j--){
            if(g[j]==0){
                g[j]=p[i];
                break;
            }
        }
    }
    int profit=0;
    for(int i=1;i<=max_d;i++){
        profit=profit+g[i];
    }
    return profit;
}

int main(){
    int n;
    cout<<"enter no of jobs ";
    cin>>n;
    int p[n+1];
    int d[n+1];
    cout<<"enter the profit ";
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    cout<<"enter the deadline ";
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
    cout<<"profit deadline before sorting "<<endl;
    display(p,d,n);
    int prof=job_seq(p,d,n);
    cout<<"profit deadline after sorting "<<endl;
    display(p,d,n);
    cout<<"maximum profit will be "<<prof;
    return 0;
}