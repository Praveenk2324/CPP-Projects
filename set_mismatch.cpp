//Leetcode 645
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int duplicate = -1;
        int missing = -1;
        vector<int> count(n+1, 0);

        for(int i =0; i < n; i++){
            count[nums[i]]++;
        }
        for(int i = 1; i <=n; i++){
            if(count[i] >= 2){
                duplicate = i;
            }
            else if(count[i] == 0){
                missing = i;
            }
        }
        return {duplicate, missing};
    }
};