#include<iostream>

#include<fstream>
using namespace std;
const int N=100;
int g[N][N]={0};
bool visited[N]={0};
void DFS(int src,int v){
    cout<<src<<"";
    visited[src]=1;
    for(int i=1;i<=v;i++){
        if(g[src][i]==1 && !visited[i]){
            DFS(i,v);
        }
    }
}

int main(){
    int v,e,src;
    ifstream infile("temp.txt");
    infile>>v>>e;
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            infile>>g[i][j];
        }
    }
    cout<<" enter the starting vertex ";
    cin>>src;
    DFS(src,v);
    return 0;
}