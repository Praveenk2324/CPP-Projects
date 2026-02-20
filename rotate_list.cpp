//Leetcode 61
#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
        ListNode* tail = head;
        int length = 1;
        while(tail->next != nullptr){
            tail = tail->next;
            length++;
        }

        k = k % length;
        if(k == 0){
            return head;
        }

        tail->next = head;

        ListNode* newTail = head;
        for(int i = 1; i < length - k; i++){
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};