//暴力破解
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }

        ListNode* pA = headA, *pB = headB;
        while(pA != nullptr){
            pB = headB;
            while(pB != nullptr){
                if(pA == pB){
                    return pA;
                }
                pB = pB->next;
            }
            pA = pA->next;
        }
        
        return nullptr;
    }
};


//哈希表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }

        ListNode* pA = headA, *pB = headB;
        unordered_set<ListNode*> s;
        while(pA != nullptr){
            s.insert(pA);
            pA = pA->next;
        }

        while(pB != nullptr){
            if(s.count(pB)){
                return pB;
            }

            pB = pB->next;
        }

        return nullptr;

    }
};


//双指针
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }

        ListNode* pA = headA, *pB = headB;
        int flag = 0;
        while(pA != pB && flag <= 2){
            if(pA == nullptr){
                pA = headB;
                flag++;
            }
            else{
                pA = pA->next;
            }

            if(pB == nullptr){
                pB = headA;
                flag++;
            }
            else{
                pB = pB->next;
            }
        }

        if(flag > 2){
            return nullptr;
        }
        else{
            return pA;
        }
    }
};
