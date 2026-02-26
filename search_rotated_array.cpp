
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
        int binary_search(vector<int>&nums, int target, int start, int end){
            while(start<=end){
                int mid = start + (end - start) / 2;
                if(nums[mid] == target){
                    return mid;
                }
                else if(target < nums[mid]){
                    end = mid -1;
                }
                else {
                    start = mid+1;
                }
            }
            return -1;
        }
    

    int search(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size() - 1;

        while(start < end){
            int mid = start + (end - start) / 2;

            if(nums[mid] > nums[end]){
                start = mid + 1;
            }
            else{
                end = mid;
            }
        }
        int pivot = start;
        if(target >= nums[pivot] && target <= nums[nums.size()-1]){
            return binary_search(nums, target, pivot, nums.size()-1);
        }
        else{
            return binary_search(nums, target, 0, pivot -1);
        }

    }
};