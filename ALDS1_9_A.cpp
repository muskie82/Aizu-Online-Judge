#include <iostream>

using namespace std;


int main(){
    int H;
    cin >> H;
    int *heap;
    heap = (int *)malloc(sizeof(int) * (H+1));
    for(int i=1; i<=H; i++)
        cin>>heap[i];
    for(int i=1; i<=H; i++){
        cout<<"Node "<<i<<": key = "<<heap[i] <<", ";
        if(i/2 >= 1) cout<< "parent key = " <<heap[i/2] <<", ";
        if(2*i <= H) cout<< "left key = " <<heap[2*i] <<", ";
        if(2*i+1 <= H) cout<<"right key = " << heap[2*i+1] <<", ";
        cout<<endl;
    }
    free(heap);
}