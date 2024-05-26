#include<iostream>
#include<fstream>

using namespace std;
#define INF  999

class Pair{
    public:
        int u;
        int v;
        int wt;
};
int main(){
    int v,e,src;
    ifstream infile("temp1.txt");
    if(!infile){
        cout<<"the file does not exist ";
    }
    infile>>v>>e;
    Pair p[100];
    for(int i=0;i<e;i++){
        infile>>p[i+1].u>>p[i+1].v>>p[i+1].wt;
    }
    int dist[v+1];
    for(int i=0;i<=v;i++){
        dist[i]=INF;
    }
    cout<<"start vertex is ";
    cin>>src;
    dist[src]=0;
    for(int i=1;i<=v;i++){
        int u=p[i].u;
        int v=p[i].v;
        int wt=p[i].wt;
        if(dist[u] != INF && dist[u]+wt<dist[v]){
            dist[v]=dist[u]+wt;
        }
    }
    for(int i=1;i<=v;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}