#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream x("temp.txt");
    int n;
    x>>n;
    vector<vector<int>>adjlist(n);
    int a[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            x>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           if(a[i][j]==1){
            adjlist[i].push_back(j);
           }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<":";
        for(int j:adjlist[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    x.close();
    return 0;
}