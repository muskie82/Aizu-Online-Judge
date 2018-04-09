#include <iostream>

using namespace std;

const int MAX=100;
const int INFTY=(1<<21);
const int WHITE=0;
const int GRAY=1;
const int BLACK=2;

int M[MAX][MAX];
int n;

void dijkstra(){
    int u,minv;
    int color[MAX],d[MAX];

    for(int i=0;i<n;i++){
        d[i]=INFTY;
        color[i]=WHITE;
    }

    d[0]=0;

    while(true){
        minv=INFTY;
        u=-1;
        for(int i=0;i<n;i++){
            if(minv>d[i] and color[i]!=BLACK){
                u=i;
                minv=d[i];
            }
        }
        if(u==-1) break;
        color[u]=BLACK;
        for(int v=0;v<n;v++){
            if(color[v]!=BLACK and M[u][v]!=INFTY){
                if (d[v]>d[u]+M[u][v]){
                    d[v]=d[u]+M[u][v];
                    color[v]=GRAY;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<i<<" "<<(d[i]==INFTY ? -1:d[i])<<endl;
    }

    return;
}

int main()
{
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            M[i][j]= INFTY;
        }
    }

    int k,c,u,v;
    for(int i=0;i<n;i++){
        cin>>u>>k;
        for(int j=0;j<k;j++){
            cin>>v>>c;
            M[u][v]=c;
        }
    }



    dijkstra();
}