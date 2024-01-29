#include<iostream>
using namespace std;


class max_heap{
    public:
    int arr[100];
    int size;
    max_heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size++;
        int index = size;
        arr[size] = val; // inserting the value at last level as leaf node
        while(index>1){
            int parent =  index / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
        
    }

    void deleteFromHeap(){
        // root node removal
        if(size == 0){
            cout<<"Empty Heap"<< endl;
            return;
        }

        int i = 1 ;
        arr[i] = arr[size];//last leaf node to first node
        size--;//remove last leaf node

        // Take root to correct position
        while(i<size){
            int left = 2*i;
            int right = 2*i +1;
            if(left < size && arr[i]<arr[left] && arr[left] > arr[right]){
                swap(arr[left], arr[i]);
                i = left;
            }
            else if( right < size && arr[i]<arr[right]){
                swap(arr[right],arr[i]);
                i = right;
            }
            else {
                return;
            }
        }


    }

    
};
void heapify(int arr[], int n , int i){
        // n - no of elements in arr. (arrSize -1 , since no element stored at 0)
        int largest  = i;
        int leftc= 2*i; // leftchild
        int rightc = 2*i +1; // rightchild

        if(leftc <= n && arr[largest]<arr[leftc] ){
            largest = leftc;
        }
        if(rightc <= n && arr[largest]<arr[rightc] ){
            largest = rightc;
        }

        if( largest !=i){
            swap(arr[largest], arr[i]);
            heapify(arr , n ,largest);
        }


    }



void heap_sorter(int arr[], int n){
    //algo steps:
    //1) swap 1st and last element of an array(last leaf node)
    //2) remove the last leaf node( n--)
    //3) heapify the remaining nodes
    //3) repeat until n = 1 

   while(n > 1){
    int i = 1;
    swap(arr[i],arr[n]);
    n--;
    // take root to correct position
     while(i<n){
            int left = 2*i;
            int right = 2*i +1;
            if(left <= n && arr[i]<arr[left] && arr[left] > arr[right]){
                swap(arr[left], arr[i]);
                i = left;
            }
            else if( right <= n && arr[i]<arr[right]){
                swap(arr[right],arr[i]);
                i = right;
            }
            else {
                break;
            }
        }
}
}

void heap_sort(int arr[] ,int arrSize){
     // for sorting 
    //1) heapify
    //2) use heapsorter
    for (int i = arrSize/2; i > 0; i--)
    {
        heapify(arr, arrSize-1, i);
        
    }
    heap_sorter(arr,arrSize -1 );

}

int main(){
    max_heap  h;
    // h.insert(34);
    // h.insert(4);
    // h.insert(234);
    // h.insert(19);
    // h.insert(10);

    // h.print();
    // h.deleteFromHeap();
    // h.print();
    int arr[] = {-1 , 85, 105, 95 , 75 , 115, 109};
    
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    
    

    for (int i = 1; i < arrSize ; i++)
    {
            h.insert(arr[i]);        
    }

    for (int i = arrSize/2; i > 0; i--)
    {       
        heapify(arr,6,i);
    }

    h.deleteFromHeap();
    h.print();

    // heap_sort(arr,arrSize);
    // cout<<"sorted array using heap sort :"<<endl;
    for (int i = 1; i < arrSize ; i++)
    {
        cout<<arr[i]<<" ";
    }
    
      return 0;
}