 #include<iostream>
using namespace std;

int binary_search(int arr[] , int target , int size){

    int low = 0;
    int high = size - 1;


    while(low<=high){
        int  mid = (low + high)/2;
        if(arr[mid] > target ){
            high = mid - 1; // first half
        }
         else if( arr[mid] < target){
            low = mid + 1; // second half
         }
         else{
            cout << target << " found at index "<< mid << endl;
            return mid;
         }
    }
    cout << target << " Not found "<< endl;
    return 0;
    

}


int main() {

    int arr[]= {12,21,23,34,45,54,67};
    int arrsize = sizeof(arr) / sizeof(arr[0]);

    // binary_search(arr,104,arrsize);
    binary_search(arr,12,arrsize);
    

    return 0;
}