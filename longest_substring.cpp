//Leetcode 3
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(256, -1);
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++){
            if(charIndex[s[right]] >= left){
                left = charIndex[s[right]]+1;
            }
            charIndex[s[right]] = right;

            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};