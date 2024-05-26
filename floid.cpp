#include<iostream>
#include<fstream>

using namespace std;
const int N=100;
int g[N][N];

int main(){
    int v,e;
    ifstream infile("temp.txt");
    if(!infile){
        cout<<"the file is not exist ";
        cout<<endl;
    }
    infile>>v>>e;
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            infile>>g[i][j];
        }
    }
    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }

    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            cout<<g[i][j];
        }
        cout<<endl;
    }
    return 0;
}