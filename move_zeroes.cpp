#include<iostream>
#include<vector>
#include<algorithm>
#include<print>

using namespace std;

void moveZeroes(vector<int>& nums){
    int writeIndex = 0;
    for(int readIndex = 0; readIndex < nums.size(); readIndex++){
        if(nums[readIndex] !=0){
            swap(nums[writeIndex], nums[readIndex]);
            writeIndex++;
        }
    }
}

void printArray(const vector<int>& arr){
    for(int num : arr)  {
        cout << num << " ";
    }
    cout << "\n";
}


int main() {
    vector<int> data = {0, 1, 0, 3, 12};
    
    cout << "Original: ";
    printArray(data);

    moveZeroes(data);

    cout << "Modified: ";
    printArray(data);

    return 0;
}