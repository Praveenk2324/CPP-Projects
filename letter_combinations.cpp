//Leetcode 17

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
private:
    void backtrack(const string& digits, int index, string& currentPath, vector<string>& result, const vector<string>& pad){
        if(index == digits.length()){
            result.push_back(currentPath);
            return;
        }

        int digit = digits[index] - '0';
        string letters = pad[digit];

        for(char letter : letters){
            currentPath.push_back(letter);
        }
    }
};