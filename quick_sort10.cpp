#include<iostream>
using namespace std;
int partition(int *arr, int start, int end) {
    int pivot = arr[start];
    int i = start + 1; // Start i at the next index
    int j = end;

    while (i <= j) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }

        while (i <= j && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[start], arr[j]);

    return j;
}


void quickSort(int *arr, int start , int end){
    if(start>=end){
        return;
    }

    int index = partition(arr,start,end);

    quickSort(arr,start,index-1);
    quickSort(arr,index+1,end);

}

int main() {
    int arr[6] = {4,45,15,15,125,115};
    quickSort(arr,0,5);
        for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    

    return 0;
}
