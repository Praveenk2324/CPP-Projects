#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums2.begin());
        int shared_min = 10;
        for(int num : nums2){
            if(set1.count(num)){
                shared_min = min(shared_min, num);
            }
        }
        if(shared_min != 10){
            return shared_min;
        }
        int min1 = *min_element(nums1.begin(), nums1.end());
        int min2 = *min_element(nums2.begin(), nums2.begin());

        return min(min1, min2) * 10 + max(min1, min2);
    }
};