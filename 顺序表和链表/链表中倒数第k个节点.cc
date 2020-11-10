/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == nullptr){
            return pListHead;
        }
        
        ListNode* curr = pListHead, *end = pListHead;
        while(k > 0 && end != nullptr){
            end = end->next;
            k--;
        }
        
        if(k != 0){
            return nullptr;
        }
        
        while(end != nullptr){
            end = end->next;
            curr = curr->next;
        }
        
        return curr;
    }
};
