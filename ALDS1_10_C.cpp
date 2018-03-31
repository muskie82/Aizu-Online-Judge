//
// Created by muskie0802 on 2018/03/30.
//

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;
static const int N=100;

int main()
{
    int n,k,v,u,j;
    int Adj[N+1][N+1]={0};

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>u>>k;
        for(j=0;j<k;j++){
            cin>>v;
            Adj[u][v]=1;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout << Adj[i][j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}

