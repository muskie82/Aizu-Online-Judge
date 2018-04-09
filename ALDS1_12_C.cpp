#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX=10000;
const int INFTY=(1<<21);
const int WHITE=0;
const int GRAY=1;
const int BLACK=2;

vector<pair<int, int> > adj[MAX];
int n;

void dijkstra(){
    priority_queue<pair<int, int> > PQ;
    int color[MAX],d[MAX];

    for(int i=0;i<n;i++){
        d[i]=INFTY;
        color[i]=WHITE;
    }

    d[0]=0;
    PQ.push(make_pair(0,0));
    color[0]=GRAY;

    while(!PQ.empty()){
        pair<int,int> f=PQ.top();PQ.pop();
        int u=f.second;
        color[u]=BLACK;

        if(d[u]<f.first*(-1)) continue;

        for(int j=0;j<adj[u].size();j++){
            int v=adj[u][j].first;
            if(color[v]==BLACK)continue;
            if (d[v]>d[u]+adj[u][j].second){
                d[v]=d[u]+adj[u][j].second;
                PQ.push(make_pair(d[v]*(-1),v));
                color[v]=GRAY;
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
    int k,u,v,c;

    for(int i=0;i<n;i++){
        cin>>u>>k;
        for(int j=0;j<k;j++){
            cin>>v>>c;
            adj[u].push_back(make_pair(v,c));
        }
    }

    dijkstra();

}