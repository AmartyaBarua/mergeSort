//
//  mergeSort.cpp
//

#include <iostream>
#include <vector>
using namespace std;

void mergeSorted(int start, int end, int arr[]);
void merge(int start,int mid, int end, int arr[]);


int main(){
    int size = 8;
    int arr[8] = {0,13,23,2,6,34,7,7};
    mergeSorted(0, size-1, arr);
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

/*recursive mergeSort function. input parameters: the starting and ending index of an array and the array itself
 returns the sorted array
 */
void mergeSorted(int start, int end, int arr[]){
    if(start==end){
        return;
    }
    else{
        int mid = (int)(start+end)/2;
//        divide the array into two halves until only 1 element remains
        mergeSorted(start,mid,arr);
        mergeSorted(mid+1,end,arr);
//        merge the two elements from each halves
        merge(start,mid,end,arr);
    }
}

/*function that insert elements from an array and inserts in in a new array in ascending order
 input parameter: the starting, middle and ending index of an array and the array itself
 creates a new array in the heap to store the sorted array. this new array will be deleted after
 copying the values.
 the values in both half of the array are compared and inserted in an ascending order
 */
void merge(int start,int mid, int end,int arr[]){
    int left_start = start;
    int right_start = mid+1;
//    new array
    int* sorted = new int[end+1];
    int resInd = 0;
//    compare the elements of the array and sort in the new array
    while(left_start<=mid && right_start<=end){
        if(arr[left_start]<=arr[right_start]){
            sorted[resInd] = arr[left_start];
            left_start++;
            resInd++;
        }
        else{
            sorted[resInd] = arr[right_start];
            right_start++;
            resInd++;
        }
    }
    if(left_start>mid){
        while(right_start<=end){
            sorted[resInd] = arr[right_start];
            resInd++;
            right_start++;
        }
    }
    else if(right_start>end){
        while(left_start<=mid){
            sorted[resInd] = arr[left_start];
            resInd++;
            left_start++;
        }
    }
    else{}
//    copy the values back to the original array
    //    note: copy the values only withing the afftected range i.e. start and end
    int arrInd,resIdx;
    for(arrInd=start,resIdx=0;arrInd<=end;arrInd++,resIdx++){
        arr[arrInd] = sorted[resIdx];
    }
    delete [] sorted;
}
