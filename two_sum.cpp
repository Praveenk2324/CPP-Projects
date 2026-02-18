#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;
    
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        
        if (sum == target) {
            // Found the pair! Return 1-based indices as per problem usually
            return {left + 1, right + 1}; 
        } 
        else if (sum > target) {
            // Sum is too large, decrease it by moving right pointer back
            right--;
        } 
        else {
            // Sum is too small, increase it by moving left pointer forward
            left++;
        }
    }
    
    return {}; // Return empty if no solution found
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    std::vector<int> result = twoSum(nums, target);
    
    std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
    
    return 0;
}