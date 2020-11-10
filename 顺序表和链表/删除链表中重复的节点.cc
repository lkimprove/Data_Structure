/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        //判空+一个节点不用进行计算
        if(pHead == nullptr || pHead->next == nullptr){
            return pHead;
        }
        
        //在头节点前设置哨兵节点
        ListNode* sen = new ListNode(0);
        sen->next = pHead;
        
        //将需要删除的节点添加至该链表，最后统一进行内存清理
        ListNode* toDelete = new ListNode(0);
        
        //prev为重复节点的前一个节点
        //curr为当前节点
        //end为重复节点的最后一个节点的下一个节点
        ListNode* prev = sen, *curr = pHead, *end = prev->next, *pt = toDelete;
        
        while(curr->next != nullptr){
            if(curr->val == curr->next->val){
                pt->next = curr;
                pt = pt->next;
                
                curr = curr->next;
                end = curr->next;
            }
            else if(prev->next == end){
                prev = prev->next;
                end = end->next;
                curr = curr->next;
            }
            else if(prev->next != end){
                prev->next = end;
                
                pt->next = curr;
                pt = pt->next;
                
                curr = curr->next;
            }
        }
        
        //如果最后一个数字为重复数字，会出现curr != end 的情况
        if(end != curr){
            prev->next = end;
            
            pt->next = curr;
            pt = pt->next;
        }
        pt->next = nullptr;
        
        
        pHead = sen->next;
        delete sen;
        sen = nullptr;
        
        //清理空间
        while(toDelete != nullptr){
            ListNode* temp = toDelete->next;
            delete toDelete;
            toDelete = temp;
        }
        
        return pHead;
    }
};
