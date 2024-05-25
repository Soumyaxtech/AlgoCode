#include<iostream>
#include<fstream>

using namespace std;

const int N=100;
int g[N][N] = {0};
bool visited[N]={0};
class Q{
    public:
        int arr[100];
        int front;
        int rear;
        Q(){
            front=-1;
            rear=-1;
        }
        void push(int val){
            rear++;
            arr[rear]=val;
        }
        int pop(){
            front++;
            return arr[front];
        }
        bool empty(){
            if(rear==front){
                return 1;
            }
            return 0;
        }
};

void BFS(int ser,int n){
    Q q;
    q.push(ser);
    visited[ser]=1;
    while(!q.empty()){
        int cur=q.pop();
        char c=char(cur+65);
        cout<<c<<" ";
        for(int i=0;i<n;i++){
            if(g[cur][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

int main(){
    int v,e,src;
    char s;
    ifstream x("temp.txt");
    x>>v>>e;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            x>>g[i][j];
        }
    }
    cout<<"GIve the st vr :";
    cin>>s;
    src=int(s-65);
    cout<<"the result of BFS is ";
    BFS(src,v);
    return 0;
}