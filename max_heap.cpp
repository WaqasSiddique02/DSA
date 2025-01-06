#include <iostream>
#include <vector>
using namespace std;

class maxHeap{
private:
    vector<int> heap;
    void heapify(int i){
        int left=2*i+1,right=2*i+2,largest=i;
        if(left<heap.size()&&heap[left]>heap[largest]){
            largest=left;
        }
        if(right<heap.size()&&heap[right]>heap[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(heap[i],heap[largest]);
            heapify(largest);
        }
    }

public:
    void insert(int value){
        heap.push_back(value);
        int i=heap.size()-1;
        while(i>0&&heap[i]>heap[(i-1)/2]){
            swap(heap[i],heap[(i-1)/2]);
            i=(i-1)/2;
        }
    }

    int extractMax(){
        int max=heap.front();
        heap[0]=heap.back();
        heapify(0);
        return  max;
    }

};

int main(){
    maxHeap heap;
    heap.insert(10);
    heap.insert(5);
    heap.insert(20);
    heap.insert(15);

    cout<<"Max Element: "<<heap.extractMax()<<endl;
    return 0;
}