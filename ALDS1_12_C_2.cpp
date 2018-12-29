#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[MAX][MAX];
vector<pair<int, int>> adj[MAX];


void dijkstra2() {
    priority_queue<pair<int, int>> PQ;
    int color[MAX];
    int d[MAX];
    for(int i=0; i<n; i++){
        d[i]=INFTY;
        color[i]=WHITE;
    }

    d[0]=0;
    PQ.push(make_pair(0,0));
    color[0]=WHITE;

    while(!PQ.empty()){
        pair<int, int> f=PQ.top(); PQ.pop();
        int u=f.second;
        color[u]=BLACK;
        if(d[u]<f.first*(-1)) continue;

        for(int j=0; j<adj[u].size(); j++){
            int v=adj[u][j].first;
            if(color[v]==BLACK) continue;
            if(d[v]>d[u]+adj[u][j].second){
                d[v]=d[u]+adj[u][j].second;
                PQ.push(make_pair(d[v]*(-1),v));
                color[v]=GRAY;
            }
        }
    }

    for (int i=0; i<n; i++){
        cout<<i<<" "<<(d[i]==INFTY ? -1:d[i]) <<endl;
    }
}


void dijkstra() {
    int minv;
    int d[MAX], color[MAX];

    for(int i=0; i<n; i++){
        d[i]=INFTY;
        color[i]=WHITE;
    }

    d[0]=0;
    color[0]=GRAY;
    while(true){
        minv=INFTY;
        int u=-1;
        for(int i=0; i<n; i++){
            if(minv>d[i] && color[i] !=BLACK){
                u=i; //find the closest point
                minv=d[i];
            }
        }
        if(u==-1) break;

        color[u]=BLACK;
        for(int v=0; v<n; v++){
            if(color[v]!=BLACK && M[u][v] !=INFTY){
                if(d[v]>d[u]+M[u][v]){
                    d[v]=d[u]+M[u][v];
                    color[v]=GRAY;
                }
            }
        }
    }

    for (int i=0; i<n; i++){
        cout<<i<<" "<<(d[i]==INFTY ? -1:d[i]) <<endl;
    }
}

int main() {
    int k, u, v, c;
    cin >> n;

    for(int i=0; i<n; i++){
        cin>>u>>k;
        for(int j=0; j<n; j++){
            cin>>v>>c;
            adj[u].push_back(make_pair(v,c));
        }
    }

    dijkstra2();

    return 0;
}