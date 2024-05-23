#include<bits/stdc++.h>

using namespace std;
int n;
int a[100][100];
int main(){
    ifstream x("temp.txt");
    int n;
    x>>n;
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            x>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    x.close();
    return 0;
}