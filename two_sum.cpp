#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int> arr, int target){
    int left = arr[0];
    int right = arr.size() - 1;

    while(left < right){
        int current_sum = arr[left] + arr[right];

        if(current_sum == target){
            return {left + 1, right + 1};
        }
        else if(current_sum > target){
            right--;
        }
        else{
            left++;
        }
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = twoSum(nums, target);
    
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
    
    return 0;
}