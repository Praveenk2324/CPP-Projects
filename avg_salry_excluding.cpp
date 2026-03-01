#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
//My code
// class Solution {
// public:
//     double average(vector<int>& salary) {
//         int max_num = INT_MIN;
//         int min_num = INT_MAX;
//         double sum = 0;
        
//         for(int i = 0; i < salary.size(); i++){
//             if (salary[i] < min_num){
//                 min_num = salary[i];   
//             }
//             if(salary[i] > max_num){
//                 max_num = salary[i];
//             }
//             sum += salary[i];
//         }
//         sum = sum - min_num - max_num;
        
//         return sum / (salary.size() - 2);
//     }
// };

//Simple code using cpp stl

class Solution {
public:
    double average(vector<int>& salary) {
        auto [min_it, max_it] = minmax_element(salary.begin(), salary.end());
        return (accumulate(salary.begin(), salary.end(), 0.0) - *min_it - *max_it) / (salary.size() - 2);
    }
};