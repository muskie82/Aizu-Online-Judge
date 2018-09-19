#include <iostream>

using namespace std;

void maxHeapify(int heap[], int H, int i){
    int max = i;
    if (2*i <= H && heap[max] < heap[2 * i])
        max = 2 * i;
    if (2*i+1 <= H && heap[max] < heap[2 * i + 1])
        max = 2 * i + 1;
    int temp = heap[i];
    if(i!=max) {
        heap[i] = heap[max];
        heap[max] = temp;
        maxHeapify(heap, H, max);
    }

}

int main(){
    int H;
    cin >> H;
    int *heap;
    heap = (int *)malloc(sizeof(int) * (H+1));
    for(int i=1; i<=H; i++)
        cin>>heap[i];

    for(int i=H/2; i>=1; i--)
        maxHeapify(heap, H, i);
    for(int i=1; i<=H; i++){
        cout<<heap[i]<<" ";
    }
    free(heap);
}