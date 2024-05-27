#include <iostream>
# include <fstream>
using namespace std;

class Edge{
public:
    int v1;
    int v2;
    int w;
};
int nov=0;
int noe=0;

Edge graph[100]={};
void readGraph(){
    ifstream myfile("kruskal.txt");
    myfile>>nov;
    myfile>>noe;
    for (int i = 0; i < noe; i++)
    {
        myfile>>graph[i].v1;
        myfile>>graph[i].v2;
        myfile>>graph[i].w;
    }
    
}

void bubble_sort(){
    for(int i=0;i<noe-1;i++){
        for(int j=0;j<noe-1;j++){
            if(graph[j].w>graph[j+1].w){
                Edge temp=graph[j];
                graph[j]=graph[j+1];
                graph[j+1]=temp;
            }
        }
    }
}
int parent[100];

void makeSet(){
    for(int i=0;i<nov;i++){
        parent[i]=-1;
    }
}

int find(int i){
    while(parent[i]>=0){
        i=parent[i];
    }
    return i;
}

void simpleUnion(int i,int j){
    parent[j]=i;
}
int tree[100][3];
int nte=0;

void kruskal(){
    bubble_sort();
    makeSet();
    for(int i=0;i<noe;i++){
        int u = find(graph[i].v1);
        int v = find(graph[i].v2);
        int we=graph[i].w;
        if (u!=v)
        {
            tree[nte][0]=graph[i].v1;
            tree[nte][1]=graph[i].v2;
            tree[nte++][2]=graph[i].w;
            simpleUnion(u,v);
        }
        
        
    }
}

void printTree(){
    for (int i = 0; i < nte; i++)
    {
        cout<<tree[i][0]<<"-----"<<tree[i][2]<<"------"<<tree[i][1]<<endl;
    }
    
}

int main(){
    readGraph();
    kruskal();
    printTree();
    return 0;
}