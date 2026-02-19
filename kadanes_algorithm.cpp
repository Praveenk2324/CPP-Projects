#include<iostream>
#include<climits>
#include<vector>
using namespace std;


int maxSubArray(vector<int>& nums) {
        int cur_sum = 0;
        int max_sum = INT_MIN;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            cur_sum += nums[i];
            max_sum = max(cur_sum, max_sum);
            if (cur_sum < 0){
                cur_sum = 0;
            }
        }
        return max_sum;
    }

void printVector(const vector<int> nums){
    cout << "[";
    for(int x : nums){
        cout << x << ", ";
    }
    cout << "]"<< endl;
}


int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout << "Array = ";
    printVector(nums);

    int result = maxSubArray(nums);
    cout << "Maximum Subarray Sum: " << result << endl;
    return 0;
    

}