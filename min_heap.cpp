#include <iostream>
#include <vector>
using namespace std;

class minHeap{
private:
    vector<int> heap;

    void heapify(int i){
        int left=2*i+1;
        int right=2*i+2;
        int smallest=i;

        if(left<heap.size()&&heap[left]<heap[smallest]){
            smallest=left;
        }
        if(right<heap.size()&&heap[right]<heap[smallest]){
            smallest=right;
        }
        if(smallest!=i){
            swap(heap[i],heap[smallest]);
            heapify(smallest);
        }
    }
public:
    void insert(int value){
        heap.push_back(value);
        int i=heap.size()-1;
        while(i>0 && heap[i]<heap[(i-1)/2]){
            swap(heap[i],heap[(i-1)/2]);
            i=(i-1)/2;
        }
    }

    int extractMin(){
        int min=heap.front();
        heap[0]=heap.back();
        heap.pop_back();
        heapify(0);
        return min;
    }
};

int main(){
    minHeap heap;
    heap.insert(10);
    heap.insert(5);
    heap.insert(20);
    heap.insert(15);

    cout<<"Min Element: "<<heap.extractMin()<<endl;
    return 0;
}