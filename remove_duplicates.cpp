#include<iostream>
#include<vector>
using namespace std;

int duplicates(vector<int>& nums){
    int slow = 1;
    int fast = 1;

    while(fast < nums.size()){
        if (nums[fast] != nums[fast - 1] ){
            nums[slow] = nums[fast];
            slow++;

        }
        fast++;
    }
    return slow;
}
int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    cout << "Original Size: " << nums.size() << endl;

    int newLength = duplicates(nums);

    cout << "New Length: " << newLength << endl;
    cout << "Modified Array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}