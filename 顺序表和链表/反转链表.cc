//迭代法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};


//头插法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = nullptr, *curr = head;

        while(curr != nullptr){
            head = curr->next;
            curr->next = newHead;
            newHead = curr;
            curr = head;
        }

        return newHead;
    }
};



//递归
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* ret = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return ret;
    }
};


//妖魔化的双指针
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return head;
        }

        ListNode* curr = head;
        while(head->next != nullptr){
            ListNode* temp = head->next->next;
            head->next->next = curr;
            curr = head->next;
            head->next = temp;
        }

        return curr;
    }
};

