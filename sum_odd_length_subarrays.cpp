
// # class Solution:
// #     def sumOddLengthSubarrays(self, arr: List[int]) -> int:
// #         n = len(arr)
// #         answer = 0

// #         for left in range(n):
// #             for right in range(left, n):
// #                 if (right - left + 1) % 2 == 1:
// #                     current_sum = 0
// #                     for index in range(left, right + 1):
// #                         current_sum += arr[index]
// #                     answer += current_sum
// #         return answer
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = int(arr.size()), answer = 0;
        
        for (int left = 0; left < n; ++left) {
            for (int right = left; right < n; ++right) {
                if ((right - left + 1) % 2 == 1) {
                    int currentSum = 0;
                    for (int index = left; index < right + 1; ++index) {
                        currentSum += arr[index];    
                    }
                    answer += currentSum;
                }
            }
        }
        return answer;
    }
};