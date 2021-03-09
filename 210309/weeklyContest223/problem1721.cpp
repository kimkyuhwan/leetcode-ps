// Swapping Nodes in a Linked List
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
    ListNode* swapNodes(ListNode* head, int k) {
      vector<int> a;
      while(head != nullptr){
        a.push_back(head->val);
        head=head->next;
      }
      int len = (a.size()-1) - (k-1);
      swap(a[k-1], a[len]);
      ListNode *newHead = new ListNode();
      ListNode *root = newHead;
      
      for(int i=0;i<a.size();i++){
        root->next = new ListNode(a[i]);
        root = root->next;
      }
      return newHead->next;
    }
};