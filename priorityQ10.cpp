#include<iostream>

using namespace std;

class node{
    public :
    string data;
    int priority;
    node(){
        priority = -1;
        data = "";
    };
    node(string d , int p){
        data = d;
        priority = p;
    }
};

class priority_q{
    void heapify(int index){
        int smallest = index;
        int leftc = 2*index + 1;
        int rightc = 2*index + 2;
       
        if(arr[leftc].priority < arr[smallest].priority && leftc < size){
            smallest = leftc;
        }
        if(arr[rightc].priority < arr[smallest].priority && rightc < size){
            smallest = rightc;
        }

        if(smallest != index){
            swap(arr[smallest],arr[index]);
            heapify(smallest);
        }
    }
    public:
    node *arr;
    int size;
    int capacity;

    priority_q(int capacity){
        this->capacity = capacity;
        this->size = 0;
        arr = new node[capacity];
    }

    void insert(string value , int priority){
         if(size == capacity){
            cout << "priority queue is full"<<endl;
            return;
         }
        node * newnode = new node(value,priority);
        arr[size] = *newnode; //  newnode --> pointer to node , *newnode --> node
        size++;
        int index = size - 1;// index of last string
         while(index > 0){
            int parent = (index-1)/2;
            if(arr[parent].priority > arr[index].priority){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                break;
            }

         }       
    }

    string highest_p_pop(){
        if(size==0){
            cout << "empty priority queue "<<endl;
            return "";
        }
        string highest_p_string = arr[0].data;

        arr[0] = arr[size-1]; // assign lowest priority element at arr[0]
        size--; // shrink the size;
        heapify(0);
        return highest_p_string;
    }
    void display(){
        for(int i=0 ; i< size ; ++i){
            cout<<arr[i].data<<endl;
        }

    }

};

int main() {
    priority_q todolist(10);
    todolist.insert("go to college",4);
    todolist.insert("wake up and brush my teeth",1);
    todolist.insert("go to bath",3);
    todolist.insert("To do exercise",2);

    // todolist.display();
    cout<<todolist.highest_p_pop()<<endl;
    cout<<todolist.highest_p_pop()<<endl;
    cout<<todolist.highest_p_pop()<<endl;
    cout<<todolist.highest_p_pop()<<endl;
   


    

    return 0;
}