#include <iostream>
using namespace std;
class MaxHeap{
    public:
    int d;
    int* arr;
    int size;
    int arrsize;
    MaxHeap(int s = 10){
        size = 0;
        arr = new int[s];
        arrsize = s;
    }
    
    void increaseSize(){
        int *arr1 = new int[size*2];
        for(int i = 0; i < size; i++){
            arr1[i] = arr[i];
        }
        arrsize = arrsize*2;
        delete [] arr;
        arr = arr1;
    }
    void heapifydown(int curr, int heapsize){
        int left = 2*curr + 1;
        int right = 2*curr + 2;
        if(left < heapsize && arr[curr] < arr[left]){
            swap(arr[curr], arr[left]);
            heapifydown(left, heapsize);
        }
        if(right < heapsize && arr[curr] < arr[right]){
            swap(arr[curr], arr[right]);
            heapifydown(right, heapsize);
        }

    }
    void heapifyup(int curr){
        int parent = ((curr - 1) / 2);
        if(parent >= 0 && arr[parent] < arr[curr]){
            swap(arr[curr], arr[parent]);
            heapifyup(parent);
        }
    }
    void buildmaxheap(int* arr, int s){
        size = s;
        for(int i = size/2 - 1; i >= 0; i--){
            heapifydown(i, size);
        }
    }
    void heapsort(int* arr, int s){
        buildmaxheap(arr, s);
        for(int i = size - 1; i >= 0; i--){
            swap(arr[0], arr[i]);
            heapifydown(0, i);
        }
    }
    void del(){
        int temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;
        size--;
        for(int i = 0; i < size; i++){
            heapifydown(i, size);
        }
    }
    void insert(int k){
        if(size == arrsize){
            increaseSize();
        }
        arr[size] = k;
        size++;
        heapifyup(size - 1);
    }
    void print(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << ' ';
        }
    }
    

};

int main(){
    MaxHeap l;
    int j[6] = {60 , 20 ,40 ,70, 30, 10};
    l.arr = j;
    l.size = 6;
    l.heapsort(l.arr, l.size);
    cout << "After heapifying array is \n";
    l.print();
    l.heapsort(l.arr, l.size);
    cout << "\nAfter heapsort: \n ";
    l.print();

    
    return 0;
}