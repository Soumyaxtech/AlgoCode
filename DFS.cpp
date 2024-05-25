#include<iostream>
#include<fstream>

using namespace std;

const int N=100;
int g[N][N] = {0};
bool visited[N]={0};
class S{
    public:
        int arr[100];
        int top;
        S(){
            top=-1;
        }
        void push(int val){
            top++;
            arr[top]=val;
        }
        int pop(){
            int val=arr[top];
            top--;
            return val;
        }
        bool empty(){
            if(top==-1){
                return 1;
            }
            return 0;
        }
};

void DFS(int ser,int n){
    S s;
    s.push(ser);
    visited[ser]=1;
    while(!s.empty()){
        int cur=s.pop();
        cout<<cur<<" ";
        for(int i=1;i<=n;i++){
            if(g[cur][i]==1 && !visited[i]){
                s.push(i);
                visited[i]=1;
            }
        }
    }
}

int main(){
    int v,e,src;
    ifstream x("temp.txt");
    x>>v>>e;
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            x>>g[i][j];
        }
    }
    cout<<"GIve the st vr :";
    cin>>src;
    cout<<"the result of DFS is ";
    DFS(src,v);
    return 0;
}