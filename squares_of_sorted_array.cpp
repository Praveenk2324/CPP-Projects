#include<iostream>
#include<vector>
using namespace std;

vector<int> sortedSquares(vector<int>& nums){
    int n = nums.size();
    vector<int> result(n);

    int left = 0;
    int right = n - 1;
    for (int i = n - 1; i >= 0; i--){
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare){
            result[i] = leftSquare;
            left++;
        }else{
            result[i] = rightSquare;
            right--;
        }
    }
    return result;
}

int main() {
    std::vector<int> nums = {-4, -1, 0, 3, 10};
    
    std::vector<int> result = sortedSquares(nums);
    
    std::cout << "Sorted Squares: ";
    for (int x : result) std::cout << x << " ";
    std::cout << std::endl;
    
    return 0;
}