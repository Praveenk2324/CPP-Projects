#include<iostream>


int binSearch(int A[],int n,int key);

int main()
{
    int A[9] = {2,4,6,7,9,11,14,16,18};
    int key = 11;
    int n = 9;
    int result = binSearch( A,n,key);
    if (result != -1) {
        std::cout << "Key found at index: " << result;
    } else {
        std::cout << "Key not found." ;
    }

    return 0;
}
int binSearch(int A[],int n,int key){
    int l = 0;
    int h = n-1;
    while(l<=h){
        int mid = (l+h)/2;
        if(key == A[mid]){
            return mid;
        }
        if(key < A[mid]){
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return -1;
}