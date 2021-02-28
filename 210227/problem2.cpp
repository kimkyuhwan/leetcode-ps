// Add Two Numbers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode();
        ListNode *root = ret;
        while(true){
            int current_value = 0;
            if(l1 != nullptr){
                current_value += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                current_value += l2->val;
                l2 = l2->next;
            }
            ret->val += current_value;
            if(ret->val > 9){
                ret->next = new ListNode(ret->val/10);
                ret->val %= 10;
            }
            else if(l1 == nullptr && l2 == nullptr) break;
            else{
                ret->next = new ListNode();
            }
            ret= ret->next;
        }
        return root;
    }
};